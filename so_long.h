/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:21:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/11 15:03:40 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> // delete
# include <fcntl.h>
# include <memory.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int	width;
	int	hight;
	char	**data;
	char	**START;
	char	**FINISH;
	char	**COLLECTIBLE;
	char	**WALLS;	
}	t_map;
int	ft_printf(char *s, ...);

#endif
