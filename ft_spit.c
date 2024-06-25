/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:24 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/24 17:11:03 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	*freeee(char **arr, size_t ii)
{
	while (ii > 0)
	{
		free(arr[ii - 1]);
		ii--;
	}
	return (NULL);
}

char	**ft_help_split(char **array, char const *s, char c, size_t split_count)
{
	size_t	i;
	char	*occ_c;

	i = 0;
	while (*s && i < split_count)
	{
		if (*s != c)
		{
			occ_c = ft_strchr(s, c);
			if (occ_c != NULL)
				array[i] = ft_substr(s, 0, occ_c - s);
			else
				array[i] = ft_strdup(s);
			if (!array[i])
				freeee(array, i);
			s += ft_strlen(array[i]);
			i++;
		}
		else
			s++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	size_t			n_c;

	if (!s)
		return (NULL);
	if (!ft_strlen(s))
	{
		res = (char **)malloc(1 * sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	n_c = ft_count_words(s, c);
	res = (char **)malloc((n_c + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	ft_help_split(res, s, c, n_c);
	res[n_c] = NULL;
	return (res);
}
