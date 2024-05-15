/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:14 by visaienk          #+#    #+#             */
/*   Updated: 2024/05/15 19:46:53 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*char	*ft_ber_map(int fd)
{
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*map;

	if (argc == 1)
		ft_printf("Map is not specied\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd)
			map = ft_ber_map(fd);
		else
			map = ft_manual_map(fd);
	}
	return (0);
}*/

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 128
#define HEIGHT 128

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
	for (int x = 0; (uint32_t)x < WIDTH; x++)
	{	
		for (int y = 0; (uint32_t)y < HEIGHT; y++)
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
}
