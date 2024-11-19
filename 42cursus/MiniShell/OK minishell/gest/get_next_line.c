/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:03:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/05 14:44:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin_gc(buffer, buf, 8);
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
		return (NULL);
	l = ft_calloc_gc((ft_strlen(b) - i + 1), sizeof(char), 8);
	i++;
	while (b[i])
		l[j++] = b[i++];
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
	line = ft_calloc_gc(i + 2, sizeof(char), 8);
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
		res = ft_calloc_gc(1, 1, 8);
	b = ft_calloc(BUFFER_SZ + 1, sizeof(char));
	b_rd = 1;
	while (b_rd > 0)
	{
		b_rd = read(fd, b, BUFFER_SZ);
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

	if (fd < 0 || BUFFER_SZ <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	b = read_file(fd, b);
	if (!b)
		return ("empty");
	l = ft_line(b);
	b = ft_next(b);
	return (l);
}
