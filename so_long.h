/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:21:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/14 21:43:52 by visaienk         ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
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
	xpm_t		*floor_t;
	xpm_t		*sprite_t;
	xpm_t		*wall_t;
	xpm_t		*coll_t;
	xpm_t		*exit_t;
}	t_mlx_assets;

typedef struct s_map
{
	int				width;
	int				height;
	char			*raw_data;
	char			**data;
	int				start_r;
	int				start_c;
	int				finish_r;
	int				finish_c;
	int				collectible;
	int				walls;
	int				steps;
	t_queue			rq;
	t_queue			cq;
	t_mlx_assets	*mlx_assets;
	mlx_t			*mlx;
}	t_map;
//ft_printf.c
int		ft_printf(char *s, ...);
void	set_depth(t_map *map);
//get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//get_next_line.c
char	*get_next_line(int fd);
//ft_utils.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *src, const char *str, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin_free(char *buffer, char *buf);
//ft_split.c
char	**ft_split(char const *s, char c);
//queue_methods.c
void	enqueue(t_queue *q, char value);
void	q_init(t_queue *q);
void	del_list(t_queue *q);
void	del_node(t_queue *q, t_node *node);
int		q_size(t_queue *q);
//map_func.c
void	ft_read_map(int fd, t_map *map);
void	rectangular_walls(t_map *map);
void	find_start_end(t_map *map);
void	find_items(t_map *map);
void	map_init(t_map *map);
//bfs_utils.c
void	kill_find_path(t_queue *rq, t_queue *cq, t_map *map, bool **a);
bool	**set_visited(int width, int height);
void	free_visited(bool **array, int height);
//bfs.c
void	explore(int r, int c, bool **a, t_map *map);
int		find_path(t_map *map);
void	map_validator(t_map *map);
int		ft_count_int(int value);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf_helper_d(int d);
// so_long_utils.c
void	so_long_kill(t_map *map);
void	ft_error(char *str, t_map *map);
void	put_img_help(int x, int y, char c, t_map *map);
void	ft_error_load(char *str, t_map *map);
void	find_forbidden_items(t_map *map);
//so_long_moves.c
void	collected(t_map *map, mlx_t *mlx);
void	move_sprite_left(t_map *map, mlx_t *mlx, int *step);
void	move_sprite_right(t_map *map, mlx_t *mlx, int *step);
void	move_sprite_up(t_map *map, mlx_t *mlx, int *step);
void	move_sprite_down(t_map *map, mlx_t *mlx, int *step);
//put_img_utils.c
void	put_wall(int x, int y, t_map *map);
void	put_coll(int x, int y, t_map *map);
void	put_floor(int x, int y, t_map *map);
void	put_sprite(t_map *map);
void	put_exit(t_map *map);

#endif
