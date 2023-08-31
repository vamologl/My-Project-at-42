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

int		deal_key(int key, fdf *data)
{
	(void)data;
	printf("%d\n", key);
	if (key == 65451)
		printf("+");
	if (key == 65362)
	{
		printf("up");
		data->modif_x -= 10;
	}
	if (key == 65364)
		printf("down");
	if (key == 65361)
		printf("left");
	if (key == 65363)
		printf("right");
	return (1);
}

int		main(int ac, char **av)
{
	fdf		*data;
	
	if (ac != 2)
	{
		printf("Erreur argument");
		return (-1);
	}

	data = (fdf *)malloc(sizeof(fdf));
	read_file(av[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 750, 750, "FdF");
	data->zoom = 8;

	//bresenham(1, 1, 499, 499, data);
	draw(data);

	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);

	return (0);
}


// main pour lire le fichier main
/*int	main(int ac, char **av)
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
}*/
