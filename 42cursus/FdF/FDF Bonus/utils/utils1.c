/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:22:21 by vamologl          #+#    #+#             */
/*   Updated: 2023/06/21 13:22:23 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[BUFFER_SIZE];
	static char	buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (output(s, line, ret, fd));
}
