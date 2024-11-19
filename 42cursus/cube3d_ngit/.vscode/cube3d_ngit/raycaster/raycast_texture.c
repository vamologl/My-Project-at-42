/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:47:28 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 14:47:33 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	get_color_side_zero(t_cube *cube, int y, int texx) // NO SO
{
	int	color;

	if (cube->ray->side == 0 && cube->ray->raydirx > 0)
		color = get_color_south(cube, y, texx);
	else if (cube->ray->side == 0 && cube->ray->raydirx < 0)
		color = get_color_north(cube, y, texx);
	return (color);
}

int	get_color_side_one(t_cube *cube, int y, int texx)
{
	int	color;

	if (cube->ray->side == 1 && cube->ray->raydiry > 0)
		color = get_color_east(cube, y, texx);
	else if (cube->ray->side == 1 && cube->ray->raydiry < 0)
		color = get_color_west(cube, y, texx);
	return (color);
}

void	get_color_texture(t_cube *cube, int y, int texx, int x)
{
	int	color;

	while (y < cube->ray->drawend)
	{
		if (cube->worldmap[cube->ray->mapx][cube->ray->mapy] == '1')
		{
			if (cube->ray->side == 0)
				color = get_color_side_zero(cube, y, texx);
			else if (cube->ray->side == 1)
				color = get_color_side_one(cube, y, texx);
		}
		else if (cube->worldmap[cube->ray->mapx][cube->ray->mapy] == 'D')
			color = get_color_doors(cube, y, texx);
		dont_draw_line(cube, x, y, color);
		y++;
	}
}
