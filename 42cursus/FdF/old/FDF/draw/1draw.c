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

void    isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int     max;
	int		z;
	int		z1;

	(void)z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z) ? 0x6b00e6 : 0x00bcff ;

	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);

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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void    draw(fdf *data)
{
    int x;
    int y;

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
    
}
