/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:49:16 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/23 11:34:22 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	get_size(t_cube *cube)
{
	if (tablen(cube->worldmap) - cube->start_map < 16)
		return (16);
	else if (tablen(cube->worldmap) - cube->start_map > 16
		&& tablen(cube->worldmap) - cube->start_map <= 32)
		return (12);
	else if (tablen(cube->worldmap) - cube->start_map > 32
		&& tablen(cube->worldmap) - cube->start_map <= 64)
		return (10);
	else if (tablen(cube->worldmap) - cube->start_map > 32)
		return (8);
	return (12);
}

void	draw_cube(t_cube *cube, int x, int y, int color)
{
	int	x1;
	int	countx;
	int	y1;
	int	county;

	county = 0;
	y1 = y * cube->size_map / 2;
	while (county < cube->size_map / 3)
	{
		x1 = x * cube->size_map / 2;
		countx = 0;
		while (countx < cube->size_map / 3)
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
	movement(cube);
	draw_background(cube, -1);
	cube->ray = malloc(sizeof(t_raycast) * 1);
	while (x < SCREENWIDTH)
	{
		cast_ray(cube, x);
		x++;
	}
	free(cube->ray);
	minimap(cube);
	animation_gest(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
	return (0);
}
