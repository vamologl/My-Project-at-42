/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:28:06 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/17 13:11:51 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	gest_key_press2(int keycode, t_cube *cube)
{
	if (keycode == 65505)
		cube->player->movespeed *= 2;
	if (keycode == 'm')
	{
		if (cube->mouse == 1)
		{
			cube->player->rotspeed = 0.01;
			cube->mouse = 0;
		}
		else if (cube->mouse == 0)
		{
			cube->player->rotspeed = 0.00075;
			cube->mouse = 1;
		}
	}
	return (0);
}

void	gest_key_press3(int keycode, t_cube *cube)
{
	if (keycode == 'p' || keycode == 'f')
	{
		if (cube->worldmap[(int)cube->player->posx]
			[(int)cube->player->posy] != 'D'
			&& cube->worldmap[(int)cube->player->posx]
			[(int)cube->player->posy] != 'O')
			check_door_around(cube);
	}
}

int	gest_key_press(int keycode, t_cube *cube)
{
	if (keycode == 65307)
		ft_gest_exit(cube);
	if (keycode == 65362 || keycode == 'w')
		cube->player->forward = 1;
	if (keycode == 'd')
		cube->player->side = 1;
	if (keycode == 'a')
		cube->player->side = -1;
	if (keycode == 65364 || keycode == 's')
		cube->player->forward = -1;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 1;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = -1;
	gest_key_press2(keycode, cube);
	gest_key_press3(keycode, cube);
	return (0);
}

int	gest_key_relase(int keycode, t_cube *cube)
{
	if (keycode == 65362 || keycode == 'w')
		cube->player->forward = 0;
	if (keycode == 'd')
		cube->player->side = 0;
	if (keycode == 'a')
		cube->player->side = 0;
	if (keycode == 65364 || keycode == 's')
		cube->player->forward = 0;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 0;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = 0;
	if (keycode == 65505)
		cube->player->movespeed /= 2;
	return (0);
}

int	movement(t_cube *cube)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cube->player->dirx;
	oldplanex = cube->player->planex;
	if (cube->player->forward == 1)
		forward_doors(cube);
	if (cube->player->side == 1)
		side_plus_doors(cube);
	if (cube->player->side == -1)
		side_minus_doors(cube);
	if (cube->player->forward == -1)
		backward_doors(cube);
	if (cube->player->rot == 1)
		rotation_plus(cube, olddirx, oldplanex);
	if (cube->player->rot == -1)
		rotation_minus(cube, olddirx, oldplanex);
	return (0);
}
