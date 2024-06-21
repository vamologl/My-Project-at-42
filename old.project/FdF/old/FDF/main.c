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

int		close_win(int key, t_fdf *data)
{
	(void)key;
	mlx_destroy_display(data->mlx_ptr);
	free(data);
	exit (2);
	return (2);
}

int		deal_key(int key, t_fdf *data)
{
	//printf("%d\n", key);
	if (key == 65453)
	{
		if (data->zoom >= 0 && (data->zoom - 2) >= 0)
			data->zoom -= 2;
	}
	if (key == 65451)
		data->zoom += 2;
	if (key == 65362)
		data->modif_y -= 10;
	if (key == 65364)
		data->modif_y += 10;
	if (key == 65361)
		data->modif_x -= 10;
	if (key == 65363)
		data->modif_x += 10;
	if (key == 65450)
		data->angle += 0.1;
	if (key == 65455)
		data->angle -= 0.1;
	if (key == 65307)
		close_win(65307, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_fdf		*data;

	if (ac != 2)
	{
		ft_printf("Erreur argument, ./FdF <Adresse Map>");
		return (-1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 750, 750, "FdF");
	data->zoom = 8;
	data->angle = 0.8;
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
