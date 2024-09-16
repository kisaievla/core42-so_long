/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/16 12:41:38 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(void *param)
{
	t_map	*map;

	map = param;
	map->mlx_assets->sprite_t = mlx_load_xpm42("./textures/sprite.xpm42");
	if (!map->mlx_assets->sprite_t)
		ft_error_load("sprite didn't load", map);
	map->mlx_assets->floor_t = mlx_load_xpm42("./textures/floor.xpm42");
	if (!map->mlx_assets->floor_t)
		ft_error_load("floor didn't load", map);
	map->mlx_assets->wall_t = mlx_load_xpm42("./textures/wall.xpm42");
	if (!map->mlx_assets->wall_t)
		ft_error_load("wall didn't load\n", map);
	map->mlx_assets->coll_t = mlx_load_xpm42("./textures/collect.xpm42");
	if (!map->mlx_assets->coll_t)
		ft_error_load("collectible didn't load\n", map);
	map->mlx_assets->exit_t = mlx_load_xpm42("./textures/exit.xpm42");
	if (!map->mlx_assets->exit_t)
		ft_error_load("exit didn't load\n", map);
}

void	make_image(void *param)
{
	t_map	*map;
	mlx_t	*mlx;

	map = param;
	mlx = map->mlx;
	map->mlx_assets->sprite = mlx_texture_to_image(mlx,
			&map->mlx_assets->sprite_t->texture);
	if (!map->mlx_assets->sprite)
		ft_error("sprite error\n", map);
	map->mlx_assets->floor = mlx_texture_to_image(mlx,
			&map->mlx_assets->floor_t->texture);
	if (!map->mlx_assets->floor)
		ft_error("texture error\n", map);
	map->mlx_assets->wall = mlx_texture_to_image(mlx,
			&map->mlx_assets->wall_t->texture);
	if (!map->mlx_assets->wall)
		ft_error("texture error\n", map);
	map->mlx_assets->coll = mlx_texture_to_image(mlx,
			&map->mlx_assets->coll_t->texture);
	if (!map->mlx_assets->coll)
		ft_error("texture error\n", map);
	map->mlx_assets->exit = mlx_texture_to_image(mlx,
			&map->mlx_assets->exit_t->texture);
	if (!map->mlx_assets->exit)
		ft_error("texture error\n", map);
}

void	put_img(t_map *map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	x = 0;
	while (i < map->height)
	{
		j = 0;
		y = 0;
		while (j < map->width)
		{
			put_img_help(x, y, map->data[i][j], map);
			y += 50;
			j++;
		}
		x += 50;
		i++;
	}
	put_sprite(map);
	//set_depth(map);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	mlx_t	*mlx;

	map = param;
	mlx = map->mlx;
	if (map->collectible == 0)
		put_exit(map);
	if ((map->data[map->start_r][map->start_c] == 'E' && map->collectible == 0)
		|| mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_sprite_left(map, mlx, &map->steps);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_sprite_right(map, mlx, &map->steps);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_sprite_up(map, mlx, &map->steps);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_sprite_down(map, mlx, &map->steps);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		ft_printf("%i\n", map->steps);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc > 2)
		ft_error("Error\nOnly one argument is allowed\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fd = 0;
	map_init(&map);
	ft_read_map(fd, &map);
	map_validator(&map);
	close(fd);
	map.mlx = mlx_init(map.width * 50, map.height * 50, "MLX42", true);
	if (!map.mlx)
		ft_error("MLX init error\n", &map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	load_textures(&map);
	make_image(&map);
	put_img(&map);
	set_depth(&map);
	write(1, "bitch\n", 7);
	mlx_key_hook(map.mlx, &my_keyhook, &map);
	mlx_loop(map.mlx);
	so_long_kill(&map);
	return (0);
}
