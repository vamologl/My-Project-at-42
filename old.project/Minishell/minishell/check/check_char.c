/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:17:40 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/10 14:12:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	nb_char(char *s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = strlen(s);
	j--;
	while ((s[j] == ' ' || s[j] == '\t') && j > 0)
		j--;
	if (j < 0)
		return (-1);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	count = 0;
	while (i <= j)
	{
		i++;
		count++;
	}
	return (count);
}

int	chk_quote(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
			{
				if (s[i++] == 0)
					return (0);
			}
		}
		if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"')
			{
				if (s[i++] == 0)
					return (0);
			}
		}
	}
	return (1);
}

int	ft_is_that_char(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (ft_strlen(s));
}
