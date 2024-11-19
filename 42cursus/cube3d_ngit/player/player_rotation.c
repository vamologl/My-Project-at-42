/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:34 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/23 11:44:20 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	rotation_plus(t_cube *cube, double olddirx, double oldplanex)
{
	cube->player->dirx = cube->player->dirx * cos(-cube->player->rotspeed)
		- cube->player->diry * sin(-cube->player->rotspeed);
	cube->player->diry = olddirx * sin(-cube->player->rotspeed)
		+ cube->player->diry * cos(-cube->player->rotspeed);
	cube->player->planex = cube->player->planex * cos(-cube->player->rotspeed)
		- cube->player->planey * sin(-cube->player->rotspeed);
	cube->player->planey = oldplanex * sin(-cube->player->rotspeed)
		+ cube->player->planey * cos(-cube->player->rotspeed);
}

void	rotation_minus(t_cube *cube, double olddirx, double oldplanex)
{
	cube->player->dirx = cube->player->dirx * cos(cube->player->rotspeed)
		- cube->player->diry * sin(cube->player->rotspeed);
	cube->player->diry = olddirx * sin(cube->player->rotspeed)
		+ cube->player->diry * cos(cube->player->rotspeed);
	cube->player->planex = cube->player->planex * cos(cube->player->rotspeed)
		- cube->player->planey * sin(cube->player->rotspeed);
	cube->player->planey = oldplanex * sin(cube->player->rotspeed)
		+ cube->player->planey * cos(cube->player->rotspeed);
}

int	gest_mouse_mov(int x, int y, t_cube *cube)
{
	double	olddirx;
	double	oldplanex;

	(void)y;
	olddirx = cube->player->dirx;
	oldplanex = cube->player->planex;
	if (cube->mouse == 1)
	{
		mlx_mouse_move(cube->mlx, cube->win, SCREENWIDTH / 2,
			SCREENHEIGHT / 2 + SCREENHEIGHT / 4);
		if (x > SCREENWIDTH / 2)
		{
			cube->player->rotspeed *= (x - SCREENWIDTH / 2);
			rotation_plus(cube, olddirx, oldplanex);
			cube->player->rotspeed /= (x - SCREENWIDTH / 2);
		}
		else if (x < SCREENWIDTH / 2)
		{
			cube->player->rotspeed *= ((x * -1) - (SCREENWIDTH / 2) * -1);
			rotation_minus(cube, olddirx, oldplanex);
			cube->player->rotspeed /= ((x * -1) - (SCREENWIDTH / 2) * -1);
		}
	}
	return (0);
}

int	check_around_player(int x, int y, t_cube *cube)
{
	if (!cube->worldmap[y][x + 1] || cube->worldmap[y][x + 1] == ' ')
		return (ERROR);
	if (!cube->worldmap[y][x - 1] || cube->worldmap[y][x - 1] == ' ')
		return (ERROR);
	if (!cube->worldmap[y + 1][x] || cube->worldmap[y + 1][x] == ' ')
		return (ERROR);
	if (!cube->worldmap[y - 1][x] || cube->worldmap[y - 1][x] == ' ')
		return (ERROR);
	return (VALID);
}

int	get_player_pos(t_cube *cube)
{
	int		x;
	int		y;
	bool	flag;

	flag = false;
	y = get_start_map(cube);
	while (++y < tablen(cube->worldmap))
	{
		x = -1;
		while (cube->worldmap[y][++x] && x < (int)ft_strlen(cube->worldmap[y]))
		{
			if (cube->worldmap[y][x] == 'N' || cube->worldmap[y][x] == 'S'
				|| cube->worldmap[y][x] == 'E' || cube->worldmap[y][x] == 'W')
			{
				if (flag == false)
					flag = set_player_pos(x, y, cube);
				else if (flag == true || check_around_player(x,
						y, cube) != VALID)
					return (ERROR);
			}
		}
	}
	if (!flag)
		return (ERROR);
	return (VALID);
}
