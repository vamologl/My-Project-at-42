/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:33:07 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 10:33:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

float	maxim(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	set_color(int z)
{
	if (z < 0)
		return (0xf6f6f6);
	else
		return (0x00bcff);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - (z + data->zoom);
}

void	struct_full_init(t_fdf *data)
{
	data->addr = NULL;
	data->img_buffer = NULL;
	data->fd = 0;
	data->bpp = 0;
	data->zoom = 0;
	data->angle = 0;
	data->tmp_x = 0;
	data->tmp_y = 0;
	data->color = 0;
	data->width = 0;
	data->endian = 0;
	data->height = 0;
	data->modif_x = 0;
	data->modif_y = 0;
	data->line_len = 0;
	data->size_win_x = 0;
	data->size_win_y = 0;
}
