/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:11:15 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/19 17:11:48 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_int(int value)
{
	int	count;

	count = 0;
	if (value > 0)
	{
		while (value > 0)
		{
			value = value / 10;
			count++;
		}
	}
	else
	{
		count = 1;
		while (value < 0)
		{
			value = value / 10;
			count++;
		}
	}
	return (count);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	m;

	if (n != -2147483648)
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		m = n % 10;
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(m + '0', fd);
	}
	else
	{
		write(fd, "-2147483648", 11);
	}
}

int	ft_printf_helper_d(int d)
{
	int	len;

	len = ft_count_int(d);
	ft_putnbr_fd(d, 1);
	return (len);
}

