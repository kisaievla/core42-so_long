/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:00:05 by visaienk          #+#    #+#             */
/*   Updated: 2024/09/16 17:00:58 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_printf_helper_c(char c)
{
	int	len;

	write(1, &c, 1);
	len = 1;
	return (len);
}

static int	ft_printf_helper_s(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
	else
		write(1, "(null)", 7);
	return (len);
}

static int	ft_printf_help(char *s, va_list argptr)
{
	int	len;

	len = 0;
	if (*s == '%')
		len += ft_printf_helper_c('%');
	else if (*s == 'c')
		len += ft_printf_helper_c(va_arg(argptr, int));
	else if (*s == 's')
		len += ft_printf_helper_s(va_arg(argptr, char *));
	else if (*s == 'd' || *s == 'i')
		len += ft_printf_helper_d(va_arg(argptr, int));
	return (len);
}

int	ft_printf(char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += ft_printf_help(s, args);
		}
		else
		{
			write(1, s, 1);
			len++;
		}
		s++;
	}
	return (len);
}

void	set_depth(t_map *map)
{
	size_t	i;

	i = 0;
	while(i < map->mlx_assets->floor->count)
	{
		mlx_set_instance_depth(&map->mlx_assets->floor->instances[i], 1);
		i++;
	}
	i = 0;
	while(i < map->mlx_assets->coll->count)
	{
		mlx_set_instance_depth(&map->mlx_assets->coll->instances[i], 2);
		i++;
	}
	mlx_set_instance_depth(&map->mlx_assets->sprite->instances[0], 23);
	//mlx_set_instance_depth(&map->mlx_assets->exit->instances[0], i + 2);
}
