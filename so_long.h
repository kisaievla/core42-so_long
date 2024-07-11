/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:21:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/11 17:58:31 by visaienk         ###   ########.fr       */
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
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif


typedef	struct s_node
{
	int		value;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
	t_node	*current;
}	t_queue;

typedef struct s_map
{
	int	width;
	int	height;
	char	*raw_data;
	char	**data;
	int	START_R;
	int	START_C;
	int	FINISH_R;
	int	FINISH_C;
	int	COLLECTIBLE;
	int	WALLS;	
}	t_map;

int	ft_printf(char *s, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *src, const char *str, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin_free(char *buffer, char *buf);
void	ft_error(char *str, t_map *map);

void	enqueue(t_queue *q, char value);
void	q_init(t_queue *q);
void	del_list(t_queue *q);
void	del_node(t_queue *q, t_node *node);
int	q_size(t_queue *q);




#endif
