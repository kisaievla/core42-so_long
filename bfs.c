/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:23:39 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/13 22:58:16 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_direction(int i, int r, int c, int **set)
{
	if (i == 0)
	{
		(*set)[0] = r - 1;
		(*set)[1] = c;
	}
	else if (i == 1)
	{
		(*set)[0] = r + 1;
		(*set)[1] = c;
	}
	else if (i == 2)
	{
		(*set)[0] = r;
		(*set)[1] = c - 1;
	}
	else if (i == 3)
	{
		(*set)[0] = r;
		(*set)[1] = c + 1;
	}
	(*set)[2] = 0;
}

void	explore(int r, int c, bool **a, t_map *map)
{
	int	*rc;
	int	i;

	i = 0;
	rc = (int *)malloc(3 * sizeof(int));
	if (!rc)
		ft_error("Explore error\n", map);
	while (i < 4)
	{
		set_direction(i, r, c, &rc);
		i++;
		if (rc[0] < 0 || rc[1] < 0)
			continue ;
		if (rc[0] >= map->height - 1 || rc[1] >= map->width - 1)
			continue ;
		if (a[rc[0]][rc[1]] == true)
			continue ;
		if (map->data[rc[0]][rc[1]] == '1')
			continue ;
		enqueue(&map->rq, rc[0]);
		enqueue(&map->cq, rc[1]);
		a[rc[0]][rc[1]] = true;
	}
	free(rc);
}

int	find_path(t_map *map)
{
	bool	**visited;
	int		r;
	int		c;

	visited = set_visited(map->width, map->height);
	q_init(&map->rq);
	q_init(&map->cq);
	enqueue(&map->rq, map->start_r);
	enqueue(&map->cq, map->start_c);
	visited[map->start_r][map->start_c] = true;
	while (q_size(&map->rq) > 0)
	{
		r = map->rq.head->value;
		c = map->cq.head->value;
		del_node(&map->rq, map->rq.head);
		del_node(&map->cq, map->cq.head);
		if (map->data[r][c] == 'E')
		{
			kill_find_path(&map->rq, &map->cq, map, visited);
			return (1);
		}
		explore(r, c, visited, map);
	}
	kill_find_path(&map->rq, &map->cq, map, visited);
	return (-1);
}

void	map_validator(t_map *map)
{
	rectangular_walls(map);
	find_forbidden_items(map);
	find_start_end(map);
	find_items(map);
	if (map->collectible == 0)
		ft_error("Error\nCollectible is missing", map);
	if (find_path(map) == -1)
		ft_error("Error\nNo path found", map);
}
