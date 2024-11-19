/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:30:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	check_symbols(t_cube *cube)
{
	int	x;
	int	y;

	y = get_start_map(cube);
	while (cube->worldmap[y] != NULL)
	{
		x = 0;
		while (cube->worldmap[y][x])
		{
			if (cube->worldmap[y][x] != 'E' && cube->worldmap[y][x] != 'W'
			&& cube->worldmap[y][x] != 'S' && cube->worldmap[y][x] != 'N'
			&& cube->worldmap[y][x] != '1' && cube->worldmap[y][x] != '0'
			&& cube->worldmap[y][x] != ' ' && cube->worldmap[y][x] != 'D'
			&& cube->worldmap[y][x] != 'O')
			{
				printf("Error symbole - %d, %d [%c]\n", y,
					x, cube->worldmap[y][x]);
				return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (VALID);
}

int	check_space(t_cube *cube, int y, int x)
{
	if (cube->worldmap[y][x] == ' ')
	{
		if (cube->worldmap[y][x + 1] != ' ' && cube->worldmap[y][x + 1] != '1')
			return (1);
		else if (x != 0 && cube->worldmap[y][x - 1] != ' '
				&& cube->worldmap[y][x - 1] != '1')
			return (2);
		else if (cube->worldmap[y + 1] && cube->worldmap[y + 1][x] != ' '
				&& cube->worldmap[y + 1][x] != '1')
			return (3);
		else if (y != 0 && cube->worldmap[y - 1][x] != ' '
				&& cube->worldmap[y - 1][x] != '1')
			return (4);
	}
	return (VALID);
}

int	check_zero(t_cube *cube, int y, int x)
{
	if (cube->worldmap[y][x] == '0')
	{
		if (!cube->worldmap[y][x + 1] || x == 0)
			return (ERROR);
		if (!cube->worldmap[y + 1] || y - 1 == get_start_map(cube) - 1)
			return (ERROR);
	}
	return (VALID);
}

int	get_start_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_strncmp(cube->worldmap[i], "F", 1) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "C", 1) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "DO", 1) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "WE", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "EA", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "NO", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "SO", 2) == 0)
			i++;
		else
			return (i);
	}
}

int	checkmap(t_cube *cube)
{
	int	x;
	int	y;

	y = get_start_map(cube);
	if (check_tab(cube, y) != VALID)
		return (ERROR);
	while (cube->worldmap[++y])
	{
		x = 0;
		while (cube->worldmap[y][x])
		{
			if (check_space(cube, y, x) != VALID)
			{
				printf("failed check space y%d x%d\n", y, x);
				return (ERROR);
			}
			if (check_zero(cube, y - 1, x) != VALID)
			{
				printf("failed check zero y%d x%d\n", y, x);
				return (ERROR);
			}
			x++;
		}
	}
	return (VALID);
}
