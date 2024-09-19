/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:18:31 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/19 23:03:07 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_kill(t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i] != NULL)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map->raw_data);
	mlx_delete_image(map->mlx, map->mlx_assets->floor);
	mlx_delete_image(map->mlx, map->mlx_assets->sprite);
	mlx_delete_image(map->mlx, map->mlx_assets->wall);
	mlx_delete_image(map->mlx, map->mlx_assets->coll);
	mlx_delete_image(map->mlx, map->mlx_assets->exit);
	mlx_delete_xpm42(map->mlx_assets->floor_t);
	mlx_delete_xpm42(map->mlx_assets->coll_t);
	mlx_delete_xpm42(map->mlx_assets->exit_t);
	mlx_delete_xpm42(map->mlx_assets->sprite_t);
	mlx_delete_xpm42(map->mlx_assets->wall_t);
	free(map->mlx_assets);
	mlx_terminate(map->mlx);
}

void	ft_error_load(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i] != NULL)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map->raw_data);
	mlx_delete_xpm42(map->mlx_assets->floor_t);
	mlx_delete_xpm42(map->mlx_assets->coll_t);
	mlx_delete_xpm42(map->mlx_assets->exit_t);
	mlx_delete_xpm42(map->mlx_assets->sprite_t);
	mlx_delete_xpm42(map->mlx_assets->wall_t);
	mlx_terminate(map->mlx);
	ft_printf(str);
	exit(1);
}

void	ft_error(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i] != NULL)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map->raw_data);
	ft_printf(str);
	exit(1);
}

void	put_img_help(int x, int y, char c, t_map *map)
{
	if (c == '1')
		put_wall(x, y, map);
	else if (c == 'C')
		put_coll(x, y, map);
	else
		put_floor(x, y, map);
}

void	find_forbidden_items(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->data[i][j] == 'C' ||
				map->data[i][j] == 'P' ||
				map->data[i][j] == '0' ||
				map->data[i][j] == '1' ||
				map->data[i][j] == 'E')
				j++;
			else
				ft_error("Error\nFound a forbidden item\n", map);
		}
		i++;
	}
}
