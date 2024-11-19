/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:47:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 14:47:50 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	get_color_west(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;
	int	frame_width;

	frame_width = 64;
	texx += cube->west_animation_frame * frame_width;
	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture->data[cube->texture->width * texy + texx];
	return (color);
}

int	get_color_east(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;
	int	frame_width;

	frame_width = 64;
	texx += cube->east_animation_frame * frame_width;
	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture2->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture2->data[cube->texture2->width * texy + texx];
	return (color);
}

int	get_color_doors(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;
	int	frame_width;

	frame_width = 64;
	texx += cube->door_animation_frame * frame_width;
	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture4->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture4->data[cube->texture4->width * texy + texx];
	return (color);
}

int	get_color_north(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;
	int	frame_width;

	frame_width = 64;
	texx += cube->north_animation_frame * frame_width;
	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture1->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture1->data[cube->texture1->width * texy + texx];
	return (color);
}

int	get_color_south(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;
	int	frame_width;

	frame_width = 64;
	texx += cube->south_animation_frame * frame_width;
	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture3->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texy >= 0 && texy < 64)
		color = cube->texture3->data[cube->texture3->width * texy + texx];
	return (color);
}
