/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:06:15 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 14:22:14 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	draw_background(t_cube *cube)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		draw_line(cube, x, SCREENHEIGHT, cube->color_f);
		draw_line(cube, x, SCREENHEIGHT / 2, cube->color_c);
		x++;
	}
}

void	dont_draw_line(t_cube *cube, int x, int y, int color)
{
	int	pixel;

	if (y < SCREENHEIGHT && x < SCREENWIDTH)
	{
		pixel = (y * cube->size_line) + (x * (cube->bits_per_pixel / 8));
		*(int *)(cube->data_addr + pixel) = color;
	}
}

void	draw_line(t_cube *cube, int x, int drawend, int color)
{
	int	y;
	int	pixel;

	y = 0;
	while (y < drawend)
	{
		y++;
		pixel = (y * cube->size_line) + (x * (cube->bits_per_pixel / 8));
		*(int *)(cube->data_addr + pixel) = color;
	}
}

void	door_minimap(t_cube *cube, int x, int y)
{
	if (cube->worldmap[y][x] == 'O')
		draw_cube(cube, y - 4, x + 1, 0x00ff00);
	if (cube->worldmap[y][x] == 'D')
		draw_cube(cube, y - 4, x + 1, 0xff0000);
}

void	minimap(t_cube *cube)
{
	int	y;
	int	x;

	y = get_start_map(cube);
	while (cube->worldmap[y])
	{
		x = 0;
		while (cube->worldmap[y][x])
		{
			if (cube->worldmap[y][x] == '0')
				draw_cube(cube, y - 4, x + 1, 0x606060);
			if (cube->worldmap[y][x] == '1')
				draw_cube(cube, y - 4, x + 1, 0xffffff);
			door_minimap(cube, x, y);
			if (cube->worldmap[y][x] == 'N' || cube->worldmap[y][x] == 'S'
				|| cube->worldmap[y][x] == 'W' || cube->worldmap[y][x] == 'E')
				draw_cube(cube, y - 4, x + 1, 0xffff00);
			x++;
		}
		y++;
	}
	draw_cube(cube, (int)cube->player->posx - 4,
		(int)cube->player->posy + 1, 0x00ffff);
}
