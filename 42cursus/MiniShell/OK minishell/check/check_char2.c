/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:19:10 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 10:17:50 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\t' || s[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

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

int	is_almost_writable(int c)
{
	if (c >= 33 && c <= 127)
		return (1);
	return (0);
}

int	check_if_storable(char *s)
{
	int	i;
	int	j;

	i = 0;
	if (!s[0])
		return (2);
	else if (s[0] == '=' && s[0])
		return (0);
	else if (s[0] >= '0' && s[0] <= '9' && s[0])
		return (0);
	else if (find_that_char(s, '=') == 1)
	{
		j = ft_is_that_char(s, '=');
		if ((int)ft_strlen(s) == j)
			return (2);
		while (i < j)
		{
			if (is_almost_writable(s[i]) == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
