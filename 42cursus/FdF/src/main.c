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

#include "../include/fdf.h"

int		close_win(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data->img_buffer);
	free(data);
	exit (2);
	return (2);
}

int		deal_key(int key, t_fdf *data)
{
	//ft_printf("%d\n", key);
	if (key == moins)
	{
		if (data->zoom >= 0 && (data->zoom - 2) >= 0)
			data->zoom -= 1;
	}
	if (key == plus)
		data->zoom += 1;
	if (key == down)
		data->modif_y -= 10;
	if (key == up)
		data->modif_y += 10;
	if (key == left)
		data->modif_x -= 10;
	if (key == right)
		data->modif_x += 10;
	if (key == etoile)
		data->angle += 0.1;
	if (key == barre)
		data->angle -= 0.1;
	if (key == echap)
		close_win(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (1);
}

void	init(t_fdf *data)
{
	data->size_win_x = 960;
	data->size_win_y = 540;
	data->modif_x = data->size_win_x / 2;
	data->modif_y = data->size_win_y / 2;
	data->zoom = 8;
	data->angle = 0.8;
}

int	main(int ac, char **av)
{
	t_fdf		*data;

	if (ac != 2)
	{
		ft_printf("Erreur d'argument, ./FdF <Adresse Map>");
		return (-1);
	}

	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);

	data->mlx_ptr = mlx_init();
	init(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_win_x , data->size_win_y, "FdF"); //DO NOT WHILE THIS FUNCTION EVEN WITH ESCAPE !!!!!!!

	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L<<17, close_win, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
