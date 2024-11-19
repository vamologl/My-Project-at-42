/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:44 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/11 13:17:11 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	check_ns(char c, t_cube *cube)
{
	cube->player->dirx = -1;
	cube->player->diry = 0;
	cube->player->planex = 0.0;
	cube->player->planey = 0.7;
	if (c == 'S')
	{
		cube->player->dirx *= -0.7;
		cube->player->planey *= -1;
	}
}

void	check_we(char c, t_cube *cube)
{
	cube->player->dirx = 0;
	cube->player->diry = 1;
	cube->player->planex = 0.7;
	cube->player->planey = -0.0;
	if (c == 'W')
	{
		cube->player->diry *= -1;
		cube->player->planex = -0.7;
	}
}

int	check_direction_player(char c, t_cube *cube)
{
	if (c == 'N' || c == 'S')
		check_ns(c, cube);
	else if (c == 'E' || c == 'W')
		check_we(c, cube);
	else
		return (ERROR);
	return (VALID);
}

bool	check_door_tex(t_cube *cube, char *str)
{
	char	*tmp;

	tmp = ft_sstrndup(str, ft_strlen(str), 3, 3);
	cube->fd_door_tex = open(tmp, O_RDONLY);
	if (cube->fd_door_tex == -1)
		return (false);
	close(cube->fd_door_tex);
	cube->door_tex_name = ft_strdup_gc(tmp, 3);
	return (true);
}

int	check_door(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->worldmap[i])
	{
		if (strncmp(cube->worldmap[i], "DO", 2) == 0)
		{
			if (check_door_tex(cube, cube->worldmap[i]) != true)
				return (ERROR);
		}
		i++;
	}
	return (0);
}
