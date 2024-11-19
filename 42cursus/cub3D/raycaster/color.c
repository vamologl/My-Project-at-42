/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:08:40 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 14:46:49 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	get_color(char *s)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;
	char	*ret;

	j = 0;
	i = 0;
	count = 0;
	ret = gc_alloc(sizeof(char *) * 1, 2);
	ret[0] = '\0';
	while (s[i] && i < ((int)ft_strlen(s)) && count < 3)
	{
		i = j;
		while (s[i] && ft_isdigit(s[i]) != 1)
			i++;
		j = i;
		while (s[i] && ft_isdigit(s[j]) == 1)
			j++;
		tmp = ft_itoa_base(ft_atoi(ft_sstrndup(s, j - i, i, 3)), 16);
		ret = ft_strjoin_gc(ret, tmp, 2);
		count++;
	}
	return (htoi(ret));
}

int	check_color(t_cube *cube)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < tablen(cube->worldmap))
	{
		if (strncmp(cube->worldmap[i], "F", 1) == 0)
		{
			cube->color_f = get_color(cube->worldmap[i]);
			count++;
		}
		else if (strncmp(cube->worldmap[i], "C", 1) == 0)
		{
			cube->color_c = get_color(cube->worldmap[i]);
			count++;
		}
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (VALID);
}
