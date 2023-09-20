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

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - (z + data->zoom);
}

void	bresenham2(float x, float y, float x1, float y1, t_fdf *data)
{
	int	max;
	float	x_step;
	float	y_step;
	
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

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = set_color(z);
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	bresenham2(x, y, x1, y1, data);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	data->img_ptr = mlx_new_image(data->mlx_ptr, data->size_win_x, data->size_win_y);
	data->img_buffer = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_len, &data->endian);
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}