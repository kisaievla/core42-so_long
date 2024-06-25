/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:11:34 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/25 18:49:48 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *src, const char *str, size_t len)
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen((char *)str);
	if (str_len == 0)
		return ((char *)src);
	if (!len)
		return (NULL);
	if (len < str_len)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i <= len - str_len)
	{
		if (ft_memcmp(&src[i], str, str_len) == 0)
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if (!dst)
		return (0);
	i = 0;
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen((char *)dst);
	if (dst_len >= size)
		return (src_len + size);
	while (i < size - dst_len - 1)
	{
		if (!src[i])
			break ;
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen((char *)src);
	if (!size)
		return (srcsize);
	while (i < size - 1 && i < srcsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (srcsize);
}

char	*ft_strjoin_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (buffer)
		free(buffer);
	return (temp);
}
