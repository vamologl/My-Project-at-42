/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:11:06 by vamologl          #+#    #+#             */
/*   Updated: 2023/06/19 16:28:21 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	get_height(char *fname)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(fname, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *fname)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(fname, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	read_file2(char *line, int i, int j, t_fdf *data)
{
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (data->z_matrix[i] == NULL)
		{
			close(data->fd);
			j = 0;
			while (j < i)
			{
				free(data->z_matrix[j]);
				i++;
			}
			free(data->z_matrix);
			return ;
		}
		i++;
	}
	i = 0;
	while (get_next_line(data->fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(data->fd);
}

void	read_file(char *fname, t_fdf *data)
{
	int		i;
	int		j;
	char	*line;

	data->fd = open(fname, O_RDONLY);
	if (data->fd < 0)
		return ;
	data->height = get_height(fname);
	data->width = get_width(fname);
	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (data->z_matrix == NULL)
	{
		close(data->fd);
		return ;
	}
	i = 0;
	j = 0;
	line = NULL;
	read_file2(line, i, j, data);
}
