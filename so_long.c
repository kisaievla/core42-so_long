/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/11 18:00:29 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(int fd, t_map *map)
{
	char	*tmp;

	map->raw_data = ft_strdup("");
	while (42)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		map->height++;
		map->raw_data = ft_strjoin_free(map->raw_data, tmp);
		free(tmp);
	}
	map->data = ft_split(map->raw_data, '\n');
	map->width = ft_strlen(map->data[0]);
}

void	rectangular_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
			ft_error("Error\nThe map is not rectangular\n", map);
		i++;
	}
	j = 0;
	while (j < map->width)
	{
		if (map->data[0][j] != '1' || map->data[map->height - 1][j] != '1')
			ft_error("Error\nThe map is not rectangular\n", map);
		j++;
	
	}
}

void	find_start_end(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->data[i][j] == 'P')
			{
				map->START_R = i;
				map->START_C = j;
			}
			else if (map->data[i][j] == 'E')
			{
				map->FINISH_R = i;
				map->FINISH_C = j;
			}
			j++;
		}
		i++;
	}
	if (map->START_R == 0 || map->FINISH_R == 0)
		ft_error("Error\nThere is no Start or Exit postion found\n", map);	
}

void	find_items(t_map *map)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->data[i][j] == 'C')
				map->COLLECTIBLE++;
			else if (map->data[i][j] == '1')
				map->WALLS++;
			else if (map->data[i][j] == 'P' && (i != map->START_R || j != map->START_C))
				ft_error("Error\nDuplicate Start postion found\n", map);
			else if (map->data[i][j] == 'E' && (i != map->FINISH_R || j != map->FINISH_C))
				ft_error("Error\nDuplicate Exit postion found\n", map);
			j++;
		}
		i++;
	}
}

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
		printf("[r-%i][c-%i] - %c\n", r, c, map->data[r][c]);
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
	write(1, "\nbitch\n", 7);
	find_start_end(map);
	find_items(map);
	if (find_path(map) == -1)
		ft_error("Error\nNo path found", map);	
	
}

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

void	map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->raw_data = NULL;
	map->data = NULL;
	map->START_R = 0;
	map->START_C = 0;
	map->FINISH_R = 0;
	map->FINISH_C = 0;
	map->COLLECTIBLE = 0;
	map->WALLS = 0;	
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
	testing(&map);
	return (0);
}

