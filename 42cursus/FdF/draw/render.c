/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:53:34 by vamologl          #+#    #+#             */
/*   Updated: 2023/09/20 10:53:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	img_pix_put(t_fdf *data, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = data->bpp - 8;
    pixel = data->img_buffer + (y * data->line_len + x * (data->bpp / 8));
    while (i >= 0)
    {
        if (data->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        else
            *pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}

void    render(t_fdf *data, int x, int y, int color)
{
    if (x < data->size_win_x && y < data->size_win_y)
    {
        if (x > 0 && y > 0)
            img_pix_put(data, x, y, color);
    }
}