/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/08 20:18:56 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map map;

void	ft_read_map(int fd)
{
	char	*tmp;

	map.raw_data = ft_strdup("");
	while (42)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		map.height++;
		map.raw_data = ft_strjoin_free(map.raw_data, tmp);
		free(tmp);
	}
	map.data = ft_split(map.raw_data, '\n');
	map.width = ft_strlen(map.data[0]);
}

void	rectangular_walls(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		if (map.data[i][0] != '1' || map.data[i][map.width - 1] != '1')
			ft_error("Error\nThe map is not rectangular\n", &map);
		i++;
	}
	j = 0;
	while (j < map.width)
	{
		if (map.data[0][j] != '1' || map.data[map.height - 1][j] != '1')
			ft_error("Error\nThe map is not rectangular\n", &map);
		j++;
	
	}
}

/*int	*stepper(int step, int pos_r, int pos_c)
{
	int	*rc;

	rc = (int *)malloc(2 * sizeof(int));
	if (step == 0)
	{	
		rc[0] = pos_r + -1;
		rc[1] = pos_c + 0;
	}
	else if (step == 1)
	{	
		rc[0] = pos_r + 1;
		rc[1] = pos_c + 0;
	}
	else if (step == 2)
	{	
		rc[0] = pos_r + 0;
		rc[1] = pos_c + -1;
	}
	else if (step == 3)
	{	
		rc[0] = pos_r + 0;
		rc[1] = pos_c + 1;
	}
	return (rc);
}

void	expore_neighbours(int r, int c, t_queue *q)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		rc = stepper(i, r, c);
		if (rc[0] < 1 || rc[1] < 1)
			continue ;
		if (rc[0] >= map.height - 2 || rc[1] >= map.width - 2)
			continue ;
		if (map.data[rc[0]][rc[1]] == '1')
			continue ;
		enqueue(q, map.data[rc[0]][rc[1]]);
	}	
}*/


void	find_start_end(void)
{
	int	i;
	int	j;

	i = 1;
	while (i < map.height - 1)
	{
		j = 1;
		while (j < map.width - 1)
		{
			if (map.data[i][j] == 'P')
			{
				map.START_R = i;
				map.START_C = j;
			}
			else if (map.data[i][j] == 'E')
			{
				map.FINISH_R = i;
				map.FINISH_C = j;
			}
			j++;
		}
		i++;
	}
	if (map.START_R == 0 || map.FINISH_R == 0)
		ft_error("Error\nThere is no Start or Exit postion found\n", &map);	
}

void	find_items(void)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < map.height - 1)
	{
		j = 1;
		while (j < map.width - 1)
		{
			if (map.data[i][j] == 'C')
				map.COLLECTIBLE++;
			else if (map.data[i][j] == '1')
				map.WALLS++;
			else if (map.data[i][j] == 'P' && (i != map.START_R || j != map.START_C))
				ft_error("Error\nDuplicate Start postion found\n", &map);
			else if (map.data[i][j] == 'E' && (i != map.FINISH_R || j != map.FINISH_C))
				ft_error("Error\nDuplicate Exit postion found\n", &map);
			j++;
		}
		i++;
	}
}

void	map_validator(void)
{
	rectangular_walls();
	find_start_end();
	find_items();
	
}

void testing()
{
	printf("Map width: %i\nMap height: %i\n", map.width, map.height);
	ft_printf("Printing the map:\n");
	int i = 0;
	while (map.data[i] != NULL)
	{
		printf("%s\n", map.data[i]);
		free(map.data[i]);
		i++;
	}
	free(map.data);
	free(map.raw_data);

}
int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
		ft_error("Error\nOnly one argument is allowed\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)	
		fd = 0;
	ft_read_map(fd);
	map_validator();
	close(fd);
	testing();
	return (0);
}

