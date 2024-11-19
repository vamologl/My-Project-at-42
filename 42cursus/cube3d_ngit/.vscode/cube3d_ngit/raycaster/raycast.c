/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:47:31 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 13:44:11 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	cast_ray4(t_cube *cube)
{
	if (cube->ray->side == 0)
		cube->ray->perpwalldist = (cube->ray->sidedistx
				- cube->ray->deltadistx);
	else
		cube->ray->perpwalldist = (cube->ray->sidedisty
				- cube->ray->deltadisty);
	cube->ray->lineheight = (int)(SCREENHEIGHT / cube->ray->perpwalldist);
	cube->ray->drawstart = -cube->ray->lineheight / 2 + SCREENHEIGHT / 2;
	if (cube->ray->drawstart < 0)
		cube->ray->drawstart = 0;
	cube->ray->drawend = cube->ray->lineheight / 2 + SCREENHEIGHT / 2;
	if (cube->ray->drawend >= SCREENHEIGHT)
		cube->ray->drawend = SCREENHEIGHT - 1;
}

void	cast_ray3(t_cube *cube)
{
	while (cube->ray->hit == 0)
	{
		if (cube->ray->sidedistx < cube->ray->sidedisty)
		{
			cube->ray->sidedistx += cube->ray->deltadistx;
			cube->ray->mapx += cube->ray->stepx;
			cube->ray->side = 0;
		}
		else
		{
			cube->ray->sidedisty += cube->ray->deltadisty;
			cube->ray->mapy += cube->ray->stepy;
			cube->ray->side = 1;
		}
		cast_ray5(cube);
	}
}

void	cast_ray2(t_cube *cube)
{
	if (cube->ray->raydirx < 0)
	{
		cube->ray->stepx = -1;
		cube->ray->sidedistx = (cube->player->posx
				- cube->ray->mapx) * cube->ray->deltadistx;
	}
	else
	{
		cube->ray->stepx = 1;
		cube->ray->sidedistx = (cube->ray->mapx
				+ 1.0 - cube->player->posx)
			* cube->ray->deltadistx;
	}
	if (cube->ray->raydiry < 0)
	{
		cube->ray->stepy = -1;
		cube->ray->sidedisty = (cube->player->posy
				- cube->ray->mapy) * cube->ray->deltadisty;
	}
	else
	{
		cube->ray->stepy = 1;
		cube->ray->sidedisty = (cube->ray->mapy + 1.0 - cube->player->posy)
			* cube->ray->deltadisty;
	}
}

void	init_raycast(int x, t_cube *cube)
{
	cube->ray->camerax = 2 * x / (double)SCREENWIDTH - 1;
	cube->ray->raydirx = cube->player->dirx
		+ cube->player->planex * cube->ray->camerax;
	cube->ray->raydiry = cube->player->diry
		+ cube->player->planey * cube->ray->camerax;
	cube->ray->mapx = (int)cube->player->posx;
	cube->ray->mapy = (int)cube->player->posy;
	if (cube->ray->raydirx == 0)
		cube->ray->deltadistx = INT_MAX;
	else
		cube->ray->deltadistx = fabs(1 / cube->ray->raydirx);
	if (cube->ray->raydiry == 0)
		cube->ray->deltadisty = INT_MAX;
	else
		cube->ray->deltadisty = fabs(1 / cube->ray->raydiry);
	cube->ray->hit = 0;
}

void	cast_ray(t_cube *cube, int x)
{
	double		wallx;
	int			texx;
	int			y;

	cube->ray = malloc(sizeof(t_raycast) * 2);
	init_raycast(x, cube);
	cast_ray2(cube);
	cast_ray3(cube);
	cast_ray4(cube);
	if (cube->ray->side == 0)
		wallx = cube->player->posy + cube->ray->perpwalldist
			* cube->ray->raydiry;
	else
		wallx = cube->player->posx + cube->ray->perpwalldist
			* cube->ray->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)64);
	y = cube->ray->drawstart;
	get_color_texture(cube, y, texx, x);
	free(cube->ray);
}
