/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:46 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/19 17:21:18 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_map *map, mlx_t *mlx)
{
	int	inst;

	inst = 0;
	if (map->data[map->START_R][map->START_C] == 'C')
	{	
		map->COLLECTIBLE--;
		inst = mlx_image_to_window(mlx, map->mlx_assets->floor,
			map->mlx_assets->sprite->instances[0].x,
			map->mlx_assets->sprite->instances[0].y);
		if (inst < 0)
       			ft_printf("floor error");
		mlx_set_instance_depth(&map->mlx_assets->floor->instances[inst], 208);	
	}
}

void	move_sprite_left(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->START_R - 1][map->START_C] != '1')
	{	
		map->mlx_assets->sprite->instances[0].y -= map->mlx_assets->sprite->height;
		map->START_R--;
		collected(map, mlx);
	}
	*step += 1;
}

void	move_sprite_right(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->START_R + 1][map->START_C] != '1')
	{	
		map->mlx_assets->sprite->instances[0].y += map->mlx_assets->sprite->height;
		map->START_R++;
		collected(map, mlx);
	}
	*step += 1;
}


void	move_sprite_up(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->START_R][map->START_C - 1] != '1')
	{	
		map->mlx_assets->sprite->instances[0].x -= map->mlx_assets->sprite->width;
		map->START_C--;
		collected(map, mlx);
	}
	*step += 1;
}

void	move_sprite_down(t_map *map, mlx_t *mlx, int *step)
{
	if (map->data[map->START_R][map->START_C + 1] != '1')
	{	
		map->mlx_assets->sprite->instances[0].x += map->mlx_assets->sprite->width;
		map->START_C++;
		collected(map, mlx);
	}
	*step += 1;
}

