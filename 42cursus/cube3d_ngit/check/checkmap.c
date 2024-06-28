/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:56:59 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/27 10:31:01 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int    check_symbols(t_cube *cube)
{
    int    x;
    int    y;

    y = 9;
    x = 0;
    while (cube->worldMap[y] != NULL)
    {
        while (cube->worldMap[y][x])
        {
            if (cube->worldMap[y][x] != 'E' && cube->worldMap[y][x] != 'W'
            && cube->worldMap[y][x] != 'S' && cube->worldMap[y][x] != 'N'
            && cube->worldMap[y][x] != '1' && cube->worldMap[y][x] != '0'
            && cube->worldMap[y][x] != ' ')
            {
                printf("%d, %d", y, x);
                return (ERROR);
            }
            x++;
        }
        x = 0;
        y++;
    }
    return (VALID);
}

int	check_space(t_cube *cube, int y, int x)
{
	if (cube->worldMap[y][x] == ' ')
	{
		if (cube->worldMap[y][x + 1] != ' ' && cube->worldMap[y][x + 1] != '1')
			return (1);
		else if (x != 0 && cube->worldMap[y][x - 1] != ' ' && cube->worldMap[y][x - 1] != '1')
			return (2);
		else if (cube->worldMap[y + 1] && cube->worldMap[y + 1][x] != ' ' && cube->worldMap[y + 1][x] != '1')
			return (3);
		else if (y != 0 && cube->worldMap[y - 1][x] != ' ' && cube->worldMap[y - 1][x] != '1')
			return (4);
	}
	return (VALID);
}

int	check_zero(t_cube *cube, int y, int x)
{

	if (cube->worldMap[y][x] == '0')
	{
		if (cube->worldMap[y][x + 1] == ' ' && cube->worldMap[y][x + 1] == '\0')
			return (5);
		else if (x != 0 && cube->worldMap[y][x - 1] == ' ')
			return (6);
		else if (cube->worldMap[y + 1] && cube->worldMap[y + 1][x] == ' ')
			return (7);
		else if (y != 0 && cube->worldMap[y - 1][x] == ' ')
			return (8);
		else if (x + 1 == (int)ft_strlen(cube->worldMap[y]))
			return (9);
		else if (x == 0)
			return (10);
	}
	return (VALID);
}

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

int	checkmap(t_cube *cube)
{
	int	x;
	int	y;

	y = 8;
	while (cube->worldMap[++y])
	{
		x = 0;
		while (cube->worldMap[y][x])
		{
			if (check_zero(cube, y, x) != VALID)
				return (ERROR);
			if (check_space(cube, y, x) != VALID)
				return (ERROR);
			x++;
		}
	}
	return (VALID);
}
