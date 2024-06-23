/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/22 19:31:48 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map map;

void	get_map_meta_data(int fd)
{
	char	*buffer;
	int	i;

	buffer = (char *)malloc(1024 * sizeof(char));
	i = -1;
	ft_printf("Getting map.width\n");
	while (42)
	{
		i = read(fd, buffer, 1);
		map.width += i;
		if(ft_strchr(buffer, '\n') || i == 0)
			break;
	}
	free(buffer);	
	buffer = (char *)malloc(map.width * sizeof(char));
	ft_printf("Getting get.hight\n");
	i = -1;
	while (i != 0)
	{
		i = read(fd, buffer, map.width);
		map.hight += i;
	}
	free(buffer);
	map.hight = (map.hight / map.width) + 1;
	buffer = NULL;
}

//char	*ft_ber_map_line(int fd)
/*void	ft_ber_map_line(int fd, char *buffer)
{
	//char	*buffer;
	int	i;

	//buffer = (char *)malloc(map.width + 1 * sizeof(char));
	while (42)
	{
		i = read(fd, buffer, 1);
		if(ft_strchr(buffer, '\n') || i == 0)
			break;
	}

	buffer[map.width] = '\0';
	//return (buffer);
}*/

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
		//free(map.data[i]);
	}
	//free(map.data);
	return (0);
}

/*#define WIDTH 512
#define HEIGHT 512

static mlx_image_t	*sprite;
static mlx_image_t	*texture;
static mlx_texture_t	*texture_t;
static mlx_texture_t	*sprite_t;

void	load_textures(void *param)
{
	mlx_t* mlx;

	mlx = param;
	sprite_t = mlx_load_png("./assets/sprite.png");
	if (!sprite)
        	ft_printf("sprite didn't load");
	
	// Convert texture to a displayable image
	sprite = mlx_texture_to_image(mlx, sprite_t);
	if (!sprite)
        	ft_printf("sprite error");
	texture_t = mlx_load_png("./assets/textures/texture.png");
	if (!texture)
        	ft_printf("texture didn't load");
	
	// Convert texture to a displayable image
	texture = mlx_texture_to_image(mlx, texture_t);
	if (!texture)
        	ft_printf("texture error");

}
void	put_img(void *param)
{
	mlx_t* mlx;

	mlx = param;
	// Display the image
	for (int x = 0; x < WIDTH; x++)
	{	
		for (int y = 0; y < HEIGHT; y++)
		{	
			if (mlx_image_to_window(mlx, texture, x, y) < 0)
        			ft_printf("texture error");
		}
	}
	if (mlx_image_to_window(mlx, sprite, 0, 0) < 0)
        	ft_printf("sprite error");

}
void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{	
		mlx_delete_image(mlx, sprite);
		mlx_close_window(mlx);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		sprite->instances[0].y -= sprite->height;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		sprite->instances[0].y += sprite->height;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		sprite->instances[0].x -= sprite->width;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		sprite->instances[0].x += sprite->width;
}

int32_t	main(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	load_textures(mlx);
	put_img(mlx);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, texture);
	mlx_delete_texture(texture_t);
	mlx_delete_texture(sprite_t);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/
