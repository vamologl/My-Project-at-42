/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_doors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:22:33 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 12:00:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	forward_doors2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'W'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'O')
		cube->player->posy += cube->player->diry * cube->player->movespeed * 4;
}

void	forward_doors(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx + cube->player->dirx
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'O')
		cube->player->posx += cube->player->dirx * cube->player->movespeed * 4;
	forward_doors2(cube);
}

void	side_plus_doors2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'W'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'O')
		cube->player->posy -= cube->player->dirx * cube->player->movespeed * 4;
}

void	side_plus_doors(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx + cube->player->diry
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'O')
		cube->player->posx += cube->player->diry * cube->player->movespeed * 4;
	side_plus_doors2(cube);
}
