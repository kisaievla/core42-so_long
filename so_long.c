/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/15 20:18:28 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void testing(t_map *map)
{
	printf("Map width: %i\nMap height: %i\n", map->width, map->height);
	ft_printf("Printing the map:\n");
	int i = 0;
	while (map->data[i] != NULL)
	{
		printf("%s\n", map->data[i]);
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map->raw_data);

}

void	load_textures(void *param)
{
	t_map	*map;
	mlx_t	*mlx;

	map = param;
	mlx = map->mlx;
	map->mlx_assets->sprite_t = mlx_load_xpm42("./textures/sprite.xpm42");
	if (!map->mlx_assets->sprite_t)
        	ft_printf("sprite didn't load");
	map->mlx_assets->floor_t = mlx_load_xpm42("./textures/floor.xpm42");
	if (!map->mlx_assets->floor_t)
        	ft_printf("floor didn't load");
	map->mlx_assets->wall_t = mlx_load_xpm42("./textures/wall.xpm42");
	if (!map->mlx_assets->wall_t)
        	ft_printf("wall didn't load");
	map->mlx_assets->coll_t = mlx_load_xpm42("./textures/collect.xpm42");
	if (!map->mlx_assets->coll_t)
        	ft_printf("sprite didn't load");
	map->mlx_assets->exit_t = mlx_load_xpm42("./textures/exit.xpm42");
	if (!map->mlx_assets->exit_t)
        	ft_printf("sprite didn't load");


	map->mlx_assets->sprite = mlx_texture_to_image(mlx, &map->mlx_assets->sprite_t->texture);
	if (!map->mlx_assets->sprite)
        	ft_printf("sprite error");
	
	map->mlx_assets->floor = mlx_texture_to_image(mlx, &map->mlx_assets->floor_t->texture);
	if (!map->mlx_assets->floor)
        	ft_printf("texture error");
	
	map->mlx_assets->wall = mlx_texture_to_image(mlx, &map->mlx_assets->wall_t->texture);
	if (!map->mlx_assets->wall)
        	ft_printf("texture error");

	map->mlx_assets->coll = mlx_texture_to_image(mlx, &map->mlx_assets->coll_t->texture);
	if (!map->mlx_assets->coll)
        	ft_printf("texture error");

	map->mlx_assets->exit = mlx_texture_to_image(mlx, &map->mlx_assets->exit_t->texture);
	if (!map->mlx_assets->exit)
        	ft_printf("texture error");


}

/*void	put_img(void *param)
{
	t_map	*map;
	mlx_t	*mlx;
	int	i;
	int	j;

	map = param;
	mlx = map->mlx;
	// Display the image
	i = 0;	
	while (i < HEIGHT)
	{	
		j = 0;
		while (j < WIDTH)
		{	
			if (i < HEIGHT / 2 && j < WIDTH / 2)
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->wall, i, j) < 0)
        				ft_printf("texture error");
			}
			else if (map->data[i - ((HEIGHT / 2) - (map->height / 2))][j - ( ((WIDTH / 2) - (map->width / 2)))] == '1')
			{
				write(1, &map->data[i - (HEIGHT / 2 + map->height)][j - (WIDTH / 2 + map->width)], 1);
				if (mlx_image_to_window(mlx, map->mlx_assets->wall, i, j) < 0)
        				ft_printf("wall error");
			}
			else if (map->data[i - (HEIGHT / 2 + map->height)][j - (WIDTH / 2 + map->width)] == '0')
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->texture, i, j) < 0)
        				ft_printf("texture error");
			}
			else
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->wall, i, j) < 0)
        				ft_printf("wall error");
			}

			j++;
		}
		i++;
	}
	if (mlx_image_to_window(mlx, map->mlx_assets->sprite, map->START_R, map->START_C) < 0)
        	ft_printf("sprite error");

}*/

void	put_img(void *param)
{
	t_map	*map;
	mlx_t	*mlx;
	int	i;
	int	j;
	int	x;
	int	y;

	map = param;
	mlx = map->mlx;
	// Display the image
	i = 0;
	x = 0;	
	while (i < map->height)
	{	
		j = 0;
		y = 0;
		while (j < map->width)
		{
			if (i < map->height && j < map->width && map->data[i][j] == '1')
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->wall, y, x) < 0)
        				ft_printf("wall error");
			}
			else if (i < map->height && j < map->width && map->data[i][j] == '0')
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->floor, y, x) < 0)
        				ft_printf("floor error");
			}
			else if (i < map->height && j < map->width && map->data[i][j] == 'C')
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->floor, y, x) < 0)
        				ft_printf("floor error");
				if (mlx_image_to_window(mlx, map->mlx_assets->coll, y, x) < 0)
        				ft_printf("collect error");
			}
			else
			{
				if (mlx_image_to_window(mlx, map->mlx_assets->floor, y, x) < 0)
        				ft_printf("floor error");	
			}
			y += 50;
			j++;
		}
		x += 50;
		i++;
	}
	if (mlx_image_to_window(mlx, map->mlx_assets->sprite, map->START_C * 50, map->START_R * 50) < 0)
        	ft_printf("sprite error");
}	


void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	mlx_t	*mlx;
	int	inst;

	map = param;
	mlx = map->mlx;
	inst = 0;
	printf("%i", map->mlx_assets->sprite->instances[0].z);
	mlx_set_instance_depth(&map->mlx_assets->sprite->instances[0], 209);
	if (map->COLLECTIBLE == 0)
	{
		if (mlx_image_to_window(mlx, map->mlx_assets->exit, map->FINISH_C * 50, map->FINISH_R * 50) < 0)
        	ft_printf("exit error");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE) || map->data[map->START_R][map->START_C] == 'E')
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{	
		if (map->data[map->START_R - 1][map->START_C] != '1')
		{	
			map->mlx_assets->sprite->instances[0].y -= map->mlx_assets->sprite->height;
			map->START_R--;
			if (map->data[map->START_R][map->START_C] == 'C')
			{	
				map->COLLECTIBLE--;
				inst = mlx_image_to_window(mlx, map->mlx_assets->floor, map->mlx_assets->sprite->instances[0].x, map->mlx_assets->sprite->instances[0].y);
				if (inst < 0)
        				ft_printf("floor error");
				mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);	
			}
		}
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{	
		if (map->data[map->START_R + 1][map->START_C] != '1')
		{
			map->mlx_assets->sprite->instances[0].y += map->mlx_assets->sprite->height;
			map->START_R++;
			if (map->data[map->START_R][map->START_C] == 'C')
			{	
				map->COLLECTIBLE--;
				inst = mlx_image_to_window(mlx, map->mlx_assets->floor, map->mlx_assets->sprite->instances[0].x, map->mlx_assets->sprite->instances[0].y);
				if (inst < 0)
        				ft_printf("floor error");
				mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);	
			}

		}
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{	
		if (map->data[map->START_R][map->START_C - 1] != '1')
		{	
			map->mlx_assets->sprite->instances[0].x -= map->mlx_assets->sprite->width;
			map->START_C--;
			if (map->data[map->START_R][map->START_C] == 'C')
			{	
				map->COLLECTIBLE--;
				inst = mlx_image_to_window(mlx, map->mlx_assets->floor, map->mlx_assets->sprite->instances[0].x, map->mlx_assets->sprite->instances[0].y);
				if (inst < 0)
        				ft_printf("floor error");
				mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);	
			}

		}
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{	
		if (map->data[map->START_R][map->START_C + 1] != '1')
		{	
			map->mlx_assets->sprite->instances[0].x += map->mlx_assets->sprite->width;
			map->START_C++;
			if (map->data[map->START_R][map->START_C] == 'C')
			{	
				map->COLLECTIBLE--;
				inst = mlx_image_to_window(mlx, map->mlx_assets->floor, map->mlx_assets->sprite->instances[0].x, map->mlx_assets->sprite->instances[0].y);
				if (inst < 0)
        				ft_printf("floor error");
				mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);	
			}
		}
	}
	printf("map.data[%i][%i] = %c\n", map->START_R, map->START_C, map->data[map->START_R][map->START_C]);
}

int	main(int argc, char **argv)
{
	int	fd;
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
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map.mlx = mlx_init(map.width * 50, map.height * 50,"MLX42", true);
	if (!map.mlx)
		exit(EXIT_FAILURE);
	load_textures(&map);
	put_img(&map);
	mlx_key_hook(map.mlx, &my_keyhook, &map);
	mlx_loop(map.mlx);
	mlx_delete_image(map.mlx, map.mlx_assets->floor);
	mlx_delete_image(map.mlx, map.mlx_assets->sprite);
	mlx_delete_image(map.mlx, map.mlx_assets->wall);
	mlx_delete_image(map.mlx, map.mlx_assets->coll);
	mlx_delete_image(map.mlx, map.mlx_assets->exit);
	mlx_delete_xpm42(map.mlx_assets->floor_t);
	mlx_delete_xpm42(map.mlx_assets->coll_t);
	mlx_delete_xpm42(map.mlx_assets->exit_t);
	mlx_delete_xpm42(map.mlx_assets->sprite_t);
	mlx_delete_xpm42(map.mlx_assets->wall_t);
	mlx_terminate(map.mlx);
	testing(&map);
	return (0);
}

