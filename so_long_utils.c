/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:18:31 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/19 17:19:17 by visaienk         ###   ########.fr       */
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
	mlx_terminate(map->mlx);
}
