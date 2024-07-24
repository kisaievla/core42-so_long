/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:20:45 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/24 19:39:07 by visaienk         ###   ########.fr       */
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
			break ;
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
				map->start_r = i;
				map->start_c = j;
			}
			else if (map->data[i][j] == 'E')
			{
				map->finish_r = i;
				map->finish_c = j;
			}
			j++;
		}
		i++;
	}
	if (map->start_r == 0 || map->finish_r == 0)
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
				map->collectible++;
			else if (map->data[i][j] == '1')
				map->walls++;
			else if (map->data[i][j] == 'P'
				&& (i != map->start_r || j != map->start_c))
				ft_error("Error\nDuplicate Start postion found\n", map);
			else if (map->data[i][j] == 'E'
				&& (i != map->finish_r || j != map->finish_c))
				ft_error("Error\nDuplicate Exit postion found\n", map);
			j++;
		}
		i++;
	}
}

void	map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->raw_data = NULL;
	map->data = NULL;
	map->start_r = 0;
	map->start_c = 0;
	map->finish_r = 0;
	map->finish_c = 0;
	map->collectible = 0;
	map->walls = 0;
	map->steps = 0;
}
