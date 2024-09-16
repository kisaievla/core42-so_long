/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:08:08 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/16 17:08:52 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(int x, int y, t_map *map)
{
	size_t	i;

	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->wall, y, x) < 0)
		ft_error("wall error\n", map);
	i = map->mlx_assets->wall->count - 1;
	mlx_set_instance_depth(&map->mlx_assets->wall->instances[i], 1);
}

void	put_coll(int x, int y, t_map *map)
{
	size_t	i;

	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->floor, y, x) < 0)
		ft_error("floor error\n", map);
	i = map->mlx_assets->floor->count - 1;
	mlx_set_instance_depth(&map->mlx_assets->floor->instances[i], 1);
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->coll, y, x) < 0)
		ft_error("collect error\n", map);
	i = map->mlx_assets->coll->count - 1;
	mlx_set_instance_depth(&map->mlx_assets->coll->instances[i], 2);
}

void	put_floor(int x, int y, t_map *map)
{
	size_t	i;

	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->floor, y, x) < 0)
		ft_error("floor error\n", map);
	i = map->mlx_assets->floor->count - 1;
	mlx_set_instance_depth(&map->mlx_assets->floor->instances[i], 1);
}

void	put_sprite(t_map *map)
{
	if (mlx_image_to_window(map->mlx, map->mlx_assets->sprite,
			map->start_c * 50, map->start_r * 50) < 0)
		ft_error("sprite error\n", map);
	mlx_set_instance_depth(&map->mlx_assets->sprite->instances[0], 3);
}

void	put_exit(t_map *map)
{
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->exit, map->finish_c * 50,
			map->finish_r * 50) < 0)
		ft_error("exit error\n", map);
	mlx_set_instance_depth(&map->mlx_assets->exit->instances[0], 4);
}
