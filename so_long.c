/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/25 12:17:48 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map map;

void	ft_raw_map(int fd)
{
	char	*tmp;
	char	*raw_data;

	raw_data = ft_strdup("");
	while (42)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		map.height++;
		raw_data = ft_strjoin(tmp, raw_data);
		write(1, "b", 1);
		//free(tmp);
	}
	map.raw_data = ft_strdup(raw_data);
	free(raw_data);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd && argc != 1)
	{	
		printf("Going into ft_ber_map\n");
		ft_raw_map(fd);
		map.data = ft_split(map.raw_data, '\n');
	}
	else
		ft_printf("Here will be function for manual map\n");//ft_manual_map(fd);
	close(fd);
	printf("Map width: %i\nMap hight: %i\n", map.width, map.height);
	ft_printf("Printing the map:\n");
	int i = 0;
	while (map.data[i] != NULL)
	{
		printf("%s\n", map.data[i]);
		free(map.data[i]);
		i++;
	}
	free(map.data);
	return (0);
}

