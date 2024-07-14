/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:21:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/14 20:02:17 by visaienk         ###   ########.fr       */
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

#define WIDTH 512
#define HEIGHT 512


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

typedef struct s_mlx_assets
{
	mlx_image_t	*sprite;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	xpm_t	*floor_t;
	xpm_t	*sprite_t;
	xpm_t	*wall_t;
	xpm_t	*coll_t;
	xpm_t	*exit_t;
}	t_mlx_assets;

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
	t_mlx_assets	*mlx_assets;
	mlx_t	*mlx;
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

void	map_init(t_map *map);
bool	**set_visited(int width, int height);
void	free_visited(bool **array, int height);
void	explore(int r, int c, bool **array, t_queue *rq,  t_queue *cq, t_map *map);
int	find_path(t_map *map);
void	map_validator(t_map *map);
void	ft_read_map(int fd, t_map *map);
void	rectangular_walls(t_map *map);
void	find_start_end(t_map *map);
void	find_items(t_map *map);
void	map_init(t_map *map);


#endif
