/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:18:22 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 13:25:30 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	side_minus_doors2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'W'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'O')
		cube->player->posy += cube->player->dirx * cube->player->movespeed * 4;
}

void	side_minus_doors(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx - cube->player->diry
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'O')
		cube->player->posx -= cube->player->diry * cube->player->movespeed * 4;
	side_minus_doors2(cube);
}

void	backward_doors2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'W'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'O')
		cube->player->posy -= cube->player->diry * cube->player->movespeed * 4;
}

void	backward_doors(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx - cube->player->dirx
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'O')
		cube->player->posx -= cube->player->dirx * cube->player->movespeed * 4;
	backward_doors2(cube);
}

bool	set_player_pos(int x, int y, t_cube *cube)
{
	check_direction_player(cube->worldmap[y][x], cube);
	cube->player->posx = y + 0.5;
	cube->player->posy = x + 0.5;
	return (true);
}
