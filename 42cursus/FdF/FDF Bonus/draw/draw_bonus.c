/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:30:07 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 10:30:08 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	print_key(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 10.25, 0xff0000, "W or UP");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 8.4, 0xff0000, "A or LEFT");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 7, 0xff0000, "S or DOWN");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 6., 0xff0000, "D or RIGHT");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 5.2, 0xff0000, "+ or - for zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 4.7, 0xff0000, "* or / for rotation");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 4.2, 0xff0000, "R for reset");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 3.75, 0xff0000, "ESC to exit");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->size_win_x / 25, \
		data->size_win_y / 3.35, 0xff0000, "P to change perspective");
}

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
	data->color = set_color(z);
	if (data->iso == 1)
	{
		isometric(&x, &y, z, data);
		isometric(&x1, &y1, z1, data);
	}
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
	print_key(data);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}
