/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:49:16 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 13:29:36 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	get_size(t_cube *cube)
{
	if (tablen(cube->worldmap) - get_start_map(cube) < 16)
		return (16);
	if (tablen(cube->worldmap) - get_start_map(cube) < 16
		&& tablen(cube->worldmap) - get_start_map(cube) > 32)
		return (8);
	if (tablen(cube->worldmap) - get_start_map(cube) > 32)
		return (4);
	return (1);
}

void	draw_cube(t_cube *cube, int x, int y, int color)
{
	int	x1;
	int	countx;
	int	y1;
	int	county;
	int	size;

	size = get_size(cube);
	county = 0;
	y1 = y * size / 2;
	while (county < size / 3)
	{
		x1 = x * size / 2;
		countx = 0;
		while (countx < size / 3)
		{
			dont_draw_line(cube, y1, x1, color);
			x1++;
			countx++;
		}
		county++;
		y1++;
	}
}

void	animation_gest(t_cube *cube)
{
	static int	count;

	if (count == 50)
	{
		count = 0;
		anim_east(cube);
		anim_south(cube);
		anim_west(cube);
		anim_north(cube);
		if (cube->check_door == 1)
			anim_door(cube);
	}
	else
		count++;
}

int	draw_loop(t_cube *cube)
{
	int	x;

	x = 0;
	cube->img = mlx_new_image(cube->mlx, SCREENWIDTH, SCREENHEIGHT);
	cube->data_addr = mlx_get_data_addr(cube->img,
			&cube->bits_per_pixel, &cube->size_line, &cube->endian);
	draw_background(cube);
	movement(cube);
	while (x < SCREENWIDTH)
	{
		cast_ray(cube, x);
		x++;
	}
	minimap(cube);
	animation_gest(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
	return (0);
}
