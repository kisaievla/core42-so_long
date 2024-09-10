/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:46 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/10 18:27:27 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_map *map, mlx_t *mlx)
{
	int	inst;

	inst = 0;
	if (map->data[map->start_r][map->start_c] == 'C')
	{
		map->collectible--;
		inst = mlx_image_to_window(mlx, map->mlx_assets->floor,
				map->mlx_assets->sprite->instances[0].x,
				map->mlx_assets->sprite->instances[0].y);
		if (inst < 0)
			ft_error("floor error\n", map);
		mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);
	}
}

void	move_sprite_left(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->start_r - 1][map->start_c] != '1')
	{
		map->mlx_assets->sprite->instances[0].y
			-= map->mlx_assets->sprite->height;
		map->start_r--;
		collected(map, mlx);
	}
	*step += 1;
}

void	move_sprite_right(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->start_r + 1][map->start_c] != '1')
	{
		map->mlx_assets->sprite->instances[0].y
			+= map->mlx_assets->sprite->height;
		map->start_r++;
		collected(map, mlx);
	}
	*step += 1;
}

void	move_sprite_up(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->start_r][map->start_c - 1] != '1')
	{
		map->mlx_assets->sprite->instances[0].x
			-= map->mlx_assets->sprite->width;
		map->start_c--;
		collected(map, mlx);
	}
	*step += 1;
}

void	move_sprite_down(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->start_r][map->start_c + 1] != '1')
	{
		map->mlx_assets->sprite->instances[0].x
			+= map->mlx_assets->sprite->width;
		map->start_c++;
		collected(map, mlx);
	}
	*step += 1;
}
