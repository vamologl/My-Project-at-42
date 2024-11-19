/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:56:59 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/11 13:17:25 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	check_ext(char *s, int len)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = len - 4;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ext[j])
		{
			i++;
			j++;
		}
		else
		{
			printf("Erreur Map, ./Cube3d <(addresse map).cub>\n");
			return (ERROR);
		}
	}
	return (VALID);
}

int	check_tab(t_cube *cube, int y)
{
	int	i;

	while (cube->worldmap[y])
	{
		i = 0;
		while (cube->worldmap[y][i])
		{
			if (cube->worldmap[y][i] == '\t')
				return (ERROR);
			i++;
		}
		y++;
	}
	return (VALID);
}

int	check_no_so(t_cube *cube)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < tablen(cube->worldmap))
	{
		if (strncmp(cube->worldmap[i], "NO", 2) == 0)
		{
			if (check_north(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		else if (strncmp(cube->worldmap[i], "SO", 2) == 0)
		{
			if (check_south(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (VALID);
}

int	check_ea_we(t_cube *cube)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < tablen(cube->worldmap))
	{
		if (strncmp(cube->worldmap[i], "EA", 2) == 00)
		{
			if (check_east(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		else if (strncmp(cube->worldmap[i], "WE", 2) == 0)
		{
			if (check_west(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (VALID);
}

int	check_textures(t_cube *cube)
{
	if (cube->check_door == 1)
	{
		if (check_door(cube) == ERROR)
			return (ERROR);
	}
	if (check_no_so(cube) == ERROR)
		return (ERROR);
	if (check_ea_we(cube) == ERROR)
		return (ERROR);
	return (VALID);
}
