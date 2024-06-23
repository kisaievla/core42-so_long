/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/23 17:42:29 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map map;

void	ft_ber_map(int fd)
{
	int	i;

	i = 0;
	map.height = 6;
	map.data = (char **)malloc((map.height + 1) * sizeof(char *));
	while (i < map.height)
	{
		map.data[i] = get_next_line(fd);
		i++;
	}
	map.data[map.height] = NULL;
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
	printf("Map width: %i\nMap hight: %i\n", map.width, map.height);
	ft_printf("Printing the map:\n");
	int i = 0;
	while (map.data[i] != NULL)
	{
		printf("%s", map.data[i]);
		free(map.data[i]);
		i++;
	}
	free(map.data);
	return (0);
}

