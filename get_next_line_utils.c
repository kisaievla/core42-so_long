/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:22:36 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/22 19:24:03 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	while ((char)ch != *str)
	{
		if (!*str)
		{
			return (0);
		}
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	if (!s1 && !s2)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
	{
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		range;
	size_t		i;

	if (!s || !(*s))
		return (NULL);
	i = ft_strlen(s);
	range = 0;
	if (start < i)
		range = i - start;
	if (range > len)
		range = len;
	str = (char *)malloc((range + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < range)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
