/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:23:39 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/11 18:32:07 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	**set_visited(int width, int height)
{
	bool	**array;
	int	i;
	int	j;

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

void	explore(int r, int c, bool **array, t_queue *rq,  t_queue *cq, t_map *map)
{
	int	rr;
	int	cc;
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
		{
			rr = r - 1;
			cc = c;
		}
		else if (i == 1)
		{
			rr = r + 1;
			cc = c;
		}
		else if (i == 2)
		{
			rr = r;
			cc = c - 1;
		}
		else if (i == 3)
		{
			rr = r;
			cc = c + 1;
		}
		i++;
		if (rr < 0 || cc < 0)
			continue ;
		if (rr >= map->height - 1 || cc >= map->width - 1)
			continue ;
		if (array[rr][cc] == true)
			continue ;
		if (map->data[rr][cc] == '1')
			continue ;
		enqueue(rq, rr);
		enqueue(cq, cc);
		array[rr][cc] = true;
	}
}

int	find_path(t_map *map)
{
	t_queue	rq;
	t_queue	cq;
	bool	**visited;
	int	r;
	int	c;

	visited = set_visited(map->width, map->height);
	q_init(&rq);
	q_init(&cq);
	enqueue(&rq, map->START_R);
	enqueue(&cq, map->START_C);
	visited[map->START_R][map->START_C] = true;
	while (q_size(&rq) > 0)
	{
		r = rq.head->value;
		c = cq.head->value;
		del_node(&rq, rq.head);
		del_node(&cq, cq.head);
	
		if (map->data[r][c] == 'E')
		{
			del_list(&rq);
			del_list(&cq);
			free_visited(visited, map->height);
			return (1);
		}
		explore(r, c, visited, &rq, &cq, map);
	}
	del_list(&rq);
	del_list(&cq);
	free_visited(visited, map->height);
	return (-1);	
}

void	map_validator(t_map *map)
{
	rectangular_walls(map);
	find_start_end(map);
	find_items(map);
	if (find_path(map) == -1)
		ft_error("Error\nNo path found", map);	
}

