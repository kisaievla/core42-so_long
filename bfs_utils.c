/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:03:22 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/23 18:52:05 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_find_path(t_queue *rq, t_queue *cq, t_map *map, bool **a)
{
	del_list(rq);
	del_list(cq);
	free_visited(a, map->height);
}

bool	**set_visited(int width, int height)
{
	bool	**array;
	int		i;
	int		j;

	array = (bool **)malloc(height * (sizeof(bool *)));
	if (!array)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		array[i] = (bool *)malloc(width * sizeof(bool));
		while (j < width)
		{
			array[i][j] = false;
			j++;
		}
		i++;
	}
	return (array);
}

void	free_visited(bool **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
