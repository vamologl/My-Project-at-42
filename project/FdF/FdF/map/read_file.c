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

void	read_file(char *fname, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(fname, O_RDONLY);
	i = 0;
	data->height = get_height(fname);
	data->width = get_width(fname);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int *) * (data->width + 1));
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
