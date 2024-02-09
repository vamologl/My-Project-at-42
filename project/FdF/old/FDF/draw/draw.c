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

void	isometric(t_coords *value, t_fdf *data)
{
	value->x = (value->x - value->y) * cos(data->angle);
	value->y = (value->x + value->y) * sin(data->angle) - (value->z + data->zoom);
}

void	bresenham2(t_coords *value, t_fdf *data)
{
	int	max;
	float	x_step;
	float	y_step;
	
	value->x += data->modif_x;
	value->x1 += data->modif_x;
	value->y += data->modif_y;
	value->y1 += data->modif_y;
	x_step = value->x1 - value->x;
	y_step = value->y1 - value->y;
	max = maxim(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(value->x - value->x1) || (int)(value->y - value->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, value->x, value->y, data->color);
		value->x += x_step;
		value->y += y_step;
	}
}

void	bresenham(t_coords *value, t_fdf *data)
{
	value->z = data->z_matrix[(int)value->y][(int)value->x];
	value->z1 = data->z_matrix[(int)value->y1][(int)value->x1];
	value->x *= data->zoom;
	value->y *= data->zoom;
	value->x1 *= data->zoom;
	value->y1 *= data->zoom;
	data->color = (value->z) ? 0x6b00e6 : 0x00bcff ;
	isometric(value, data);
	isometric(value, data);
	bresenham2(value, data);
}

void	draw(t_fdf *data)
{
	t_coords	*value;

	value->y = 0;
	while (value->y < data->height)
	{
		value->x = 0;
		while (value->x < data->width)
		{
			if (value->x < data->width - 1)
			{
				value->x1 = value->x + 1;
				bresenham(value, data);
			}
			if (value->y < data->height - 1)
			{
				value->y1 = value->y + 1;
				bresenham(value, data);
			}
			value->x = value->x + 1;
		}
		value->y = value->y + 1;
	}
}

/*void	draw(t_fdf *data)
{
	t_coords	*value;
	float	x;
	float	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(value, data);
			if (y < data->height - 1)
				bresenham(value, data);
			x++;
		}
		y++;
	}
}*/

