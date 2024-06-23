/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/23 16:51:27 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map map;

void	ft_ber_map(int fd)
{
	int	i;

	i = 0;
	ft_printf("Going into get_map_data(fd)\n");
	get_map_meta_data(fd);
	map.data = (char **)malloc(map.hight + 1 * sizeof(char *));
	while (i < map.hight)
	{
		map.data[i] = get_next_line(fd);
		printf("LINE: '%s'\n",  map.data[i]);
		i++;
	}
	map.data[map.hight + 1] = NULL;
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	ft_printf("Going into ft_ber_map\n");
	if (fd && argc != 1)
		ft_ber_map(fd);
	else
		ft_printf("Here will be function for manual map\n");//ft_manual_map(fd);
	close(fd);
	printf("Map width: %i\nMap hight: %i\n", map.width, map.hight);
	ft_printf("Printing the map:\n");
	for (int i = 0; i < map.hight; i++)
	{
		ft_printf("%s\n", map.data[i]);
		free(map.data[i]);
	}
	free(map.data);
	return (0);
}

