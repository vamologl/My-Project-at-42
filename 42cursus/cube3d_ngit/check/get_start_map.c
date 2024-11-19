/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:40:46 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/23 11:41:10 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	get_start_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->worldmap[i])
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
	return (0);
}
