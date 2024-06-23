/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:21:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/22 19:25:03 by visaienk         ###   ########.fr       */
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
	char	*raw_data;
	char	**data;
	char	**START;
	char	**FINISH;
	char	**COLLECTIBLE;
	char	**WALLS;	
}	t_map;
int	ft_printf(char *s, ...);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
