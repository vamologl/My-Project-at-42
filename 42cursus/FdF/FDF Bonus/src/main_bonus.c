/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:32:16 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/30 13:33:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	init(t_fdf *data)
{
	data->size_win_x = 960;
	data->size_win_y = 540;
	data->modif_x = data->size_win_x / 2;
	data->modif_y = data->size_win_y / 2;
	data->zoom = 12;
	data->angle = 0.762;
	data->iso = 1;
}

int	close_win(t_fdf *data)
{
	int	j;

	j = 0;
	while (j < data->height)
	{
		free(data->z_matrix[j]);
		j++;
	}
	free(data->z_matrix);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit (2);
	return (2);
}

void	deal_key2(int key, t_fdf *data)
{
	if (key == star)
		data->angle += 0.1;
	if (key == dash)
		data->angle -= 0.1;
	if (key == R_key)
	{
		data->zoom = 12;
		data->angle = 0.762;
		data->modif_x = data->size_win_x / 2;
		data->modif_y = data->size_win_y / 2;
	}
	if (key == P_key)
		data->iso = data->iso * -1;
	draw(data);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == esc)
		close_win(data);
	if (key == minus && data->zoom >= 0 && data->zoom - 1 >= 0)
	{
		if (data->zoom >= 0 && (data->zoom - 2) >= 0)
			data->zoom -= 1;
	}
	if (key == add)
		data->zoom += 1;
	if (key == down || key == W_key)
		data->modif_y -= 10;
	if (key == up || key == S_key)
		data->modif_y += 10;
	if (key == left || key == A_key)
		data->modif_x -= 10;
	if (key == right || key == D_key)
		data->modif_x += 10;
	deal_key2(key, data);
	return (1);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
	{
		ft_printf("Erreur d'argument, ./FdF <Adresse Map>");
		return (-1);
	}
	check_map(av[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	struct_full_init(data);
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	init(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_win_x, \
		data->size_win_y, "FdF");
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_win, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
