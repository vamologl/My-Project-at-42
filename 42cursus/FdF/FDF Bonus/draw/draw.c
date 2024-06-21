/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:14:32 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/29 11:14:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	img_gest(t_fdf *data, float x, float y, int i)
{
	if (i == 1)
	{
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->size_win_x, \
			data->size_win_y);
		data->img_buffer = mlx_get_data_addr(data->img_ptr, &data->bpp, \
			&data->line_len, &data->endian);
	}
	else if (i == 2)
	{
		data->tmp_x = x;
		data->tmp_y = y;
		bresenham(x + 1, y, data);
	}
	else if (i == 3)
	{
		data->tmp_x = x;
		data->tmp_y = y;
		bresenham(x, y + 1, data);
	}
	else
		return ;
}

void	bresenham2(float x1, float y1, t_fdf *data)
{
	int		max;
	float	x_step;
	float	y_step;
	float	x;
	float	y;

	x = data->tmp_x;
	y = data->tmp_y;
	x += data->modif_x;
	x1 += data->modif_x;
	y += data->modif_y;
	y1 += data->modif_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = maxim(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		render(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	bresenham(float x1, float y1, t_fdf *data)
{
	int		z;
	int		z1;
	float	x;
	float	y;

	x = data->tmp_x;
	y = data->tmp_y;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = 0xffffff;
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	data->tmp_x = x;
	data->tmp_y = y;
	bresenham2(x1, y1, data);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	img_gest(data, x, y, 1);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				img_gest(data, x, y, 2);
			if (y < data->height - 1)
				img_gest(data, x, y, 3);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}
