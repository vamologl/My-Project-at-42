/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:36:25 by vamologl          #+#    #+#             */
/*   Updated: 2023/06/19 14:54:14 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	fdf	*data;

	(void)ac;
	i = 0;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(av[1], data);
	while (i < data->height)
	{
		j = 0;
		while (j < data ->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
/*
int	main(int ac, char **av)
{
	char *l;
	int	fd;
	(void)ac;
	//int	i = 0;

	fd = open(av[1], O_RDONLY);
	l = (char *)malloc(sizeof(char) + 1);
	while (get_next_line(fd, &l))
	{
		//printf("%d\n", i);
		printf("%s\n", l);
		//i++;
	}
	close (fd);
	return (0);
}*/
