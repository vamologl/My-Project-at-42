/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:06:15 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/23 11:42:41 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	draw_background(t_cube *cube, int y)
{
	int	x;
	int	pixel;
	int	bpp;
	int	color;
	int	line_offset;

	bpp = cube->bits_per_pixel / 8;
	while (++y < SCREENHEIGHT)
	{
		line_offset = y * cube->size_line;
		if (y < cube->half_screen)
			color = cube->color_c;
		else
			color = cube->color_f;
		x = -1;
		while (++x < SCREENWIDTH)
		{
			pixel = line_offset + (x * bpp);
			*(int *)(cube->data_addr + pixel) = color;
		}
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
	if (cube->worldmap[y][x] == '0')
		draw_cube(cube, y - 4, x + 1, 0x606060);
	else if (cube->worldmap[y][x] == '1')
		draw_cube(cube, y - 4, x + 1, 0xffffff);
	else if (cube->worldmap[y][x] == 'N' || cube->worldmap[y][x] == 'S'
		|| cube->worldmap[y][x] == 'W' || cube->worldmap[y][x] == 'E')
		draw_cube(cube, y - 4, x + 1, 0xffff00);
	else if (cube->worldmap[y][x] == 'O')
		draw_cube(cube, y - 4, x + 1, 0x00ff00);
	else if (cube->worldmap[y][x] == 'D')
		draw_cube(cube, y - 4, x + 1, 0xff0000);
}

void	minimap(t_cube *cube)
{
	int	y;
	int	x;

	y = cube->start_map;
	while (cube->worldmap[y])
	{
		x = -1;
		while (cube->worldmap[y][++x])
			door_minimap(cube, x, y);
		y++;
	}
	draw_cube(cube, (int)cube->player->posx - 4,
		(int)cube->player->posy + 1, 0x00ffff);
}
