/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:17:40 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/17 13:03:38 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error(int i, t_base *base)
{
	if (i == 0)
	{
		ft_putstr_fd("Error -", 1);
		ft_putstr_fd(base->tableau[0][0], 1);
		ft_putstr_fd(" command not found\n", 1);
	}
	else if (i == 1)
	{
		ft_putstr_fd("exit not free'd\n", 1);
		exit_prog(0, base->env_old, base);
		exit(1273);
	}
}

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

int	hm_ultra_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
