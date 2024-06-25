/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:18:32 by visaienk          #+#    #+#             */
/*   Updated: 2024/06/25 18:58:55 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_one_line(int fd, char *stash)
{
	char	*buffer;
	int	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (42)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin_free(stash, buffer);
		if (ft_strchr(stash, '\n') || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp;
	char		*line;
	int		len;

	if (fd < 0 || fd > FD_SETSIZE)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = get_one_line(fd, stash);
	if (!stash)
		return (NULL);
	len = ft_strchr(stash, '\n') - stash;
	line = ft_substr(stash, 0, len + 1);
	temp = stash;
	stash = ft_substr(stash, len + 1, (ft_strlen(stash) - len));
	free(temp);
	return (line);
}
