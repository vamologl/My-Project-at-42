/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:31:42 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 10:31:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	check_empty(void)
{
	ft_printf("Map vide");
	exit (-3);
}

void	check_ext(char *s, int len)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".fdf";
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
			ft_printf("Erreur Map, ./fdf <(addresse map).fdf>\n");
			exit (-2);
		}
	}
}

void	check_map(char *s)
{
	int		len;

	len = ft_strlen(s);
	check_ext(s, len);
}

void	print_map(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data-> width)
		{
			ft_printf("%3d", data->z_matrix[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
