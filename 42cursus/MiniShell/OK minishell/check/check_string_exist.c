/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:06 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/12 13:44:22 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_there_char(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	get_input_tab(t_base *base, int i)
{
	int		j;

	j = 0;
	base->tableau[i] = ft_super_split(base->input);
	base->tablen = 1;
	while (base->tableau[i][j])
	{
		base->tableau[i][j] = modif_token(base->tableau[i][j], base);
		j++;
	}
}

int	check_empty_tab(char **tab)
{
	int	i;

	i = ft_tablen(tab);
	i--;
	while (i >= 0)
	{
		if (tab && tab[0])
			i--;
		else
			return (1);
	}
	return (0);
}

int	no_command(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_find_redirection(av[i]) != 0)
			i += 2;
		else
			return (0);
	}
	return (1);
}

int	check_pipe(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"' && s[i] != '\0')
				i++;
		}
		if (s[i] == '|')
			return (i);
		i++;
	}
	return (0);
}
