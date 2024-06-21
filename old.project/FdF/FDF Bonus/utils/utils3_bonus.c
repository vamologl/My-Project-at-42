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
	if (z <= 0)
		return (0xffffff);
	else
		return (0x00bcff);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - (z + data->zoom);
}
