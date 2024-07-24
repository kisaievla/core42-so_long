/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:08:08 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/24 19:44:30 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(int x, int y, t_map *map)
{
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->wall, y, x) < 0)
		ft_printf("wall error");
}

void	put_coll(int x, int y, t_map *map)
{
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->floor, y, x) < 0)
		ft_printf("floor error");
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->coll, y, x) < 0)
		ft_printf("collect error");
}

void	put_floor(int x, int y, t_map *map)
{
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->floor, y, x) < 0)
		ft_printf("floor error");
}

void	put_sprite(t_map *map)
{
	if (mlx_image_to_window(map->mlx, map->mlx_assets->sprite,
			map->start_c * 50, map->start_r * 50) < 0)
		ft_printf("sprite error");
}

void	put_exit(t_map *map)
{
	if (mlx_image_to_window(map->mlx,
			map->mlx_assets->exit, map->finish_c * 50,
			map->finish_r * 50) < 0)
		ft_printf("exit error");
}
