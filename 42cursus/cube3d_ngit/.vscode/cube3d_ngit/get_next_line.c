/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:04:33 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/03 14:15:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_next(char *b)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free(b);
		return (NULL);
	}
	l = ft_calloc((ft_strlen(b) - i + 1), sizeof(char));
	i++;
	while (b[i])
		l[j++] = b[i++];
	free(b);
	return (l);
}

char	*ft_line(char *b)
{
	char	*line;
	int		i;

	i = 0;
	if (!b[i])
		return (NULL);
	while (b[i] && b[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (b[i] && b[i] != '\n')
	{
		line[i] = b[i];
		i++;
	}
	if (b[i] && b[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*b;
	int		b_rd;

	if (!res)
		res = ft_calloc(1, 1);
	b = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_rd = 1;
	while (b_rd > 0)
	{
		b_rd = read(fd, b, BUFFER_SIZE);
		if (b_rd == -1)
		{
			free(b);
			return (NULL);
		}
		b[b_rd] = 0;
		res = ft_free(res, b);
		if (ft_strchr(b, '\n'))
			b_rd = -1;
	}
	free(b);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	b = read_file(fd, b);
	if (!b)
		return (NULL);
	l = ft_line(b);
	b = ft_next(b);
	return (l);
}
