/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:05 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/07 14:04:44 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	chrcmp(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

int	hm_pipe(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (chrcmp(s[i], "|") == 0)
			count++;
		i++;
	}
	return (count);
}

int	find_pipe(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (chrcmp(s[i], "|") == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	tablen_pipe(char **tab, int i)
{
	int	j;

	j = i;
	if (!tab)
		return (0);
	while (tab[j] != NULL && ft_strcmp(tab[j], "|") != 0)
	{
		if (tab[j + 1] == NULL)
			return ((j - i) + 1);
		j++;
	}
	return (j - i);
}

char	***pre_build_tab(t_base *base, char *s)
{
	char	***tab;

	if (find_pipe(s) == -1)
		return (NULL);
	tab = ft_ultra_split(s, base);
	if (!tab)
		return (NULL);
	gest_dollar_multipipe(base, 0);
	return (tab);
}
