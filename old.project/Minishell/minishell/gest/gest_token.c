/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:10 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 10:29:59 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	***ft_ultra_while(int j, int k, char ***tab, char **tmp)
{
	int	i;

	i = 0;
	while (tmp && i < ft_tablen(tmp))
	{
		tab[j] = gc_alloc(sizeof(char **) * (tablen_pipe(tmp, i) + 2), 3);
		if (!tab[j])
			return (NULL);
		k = 0;
		while (tmp[i] && ft_strcmp(tmp[i], "|") != 0)
		{
			tab[j][k] = ft_strdup_gc(tmp[i], 1);
			i++;
			k++;
		}
		tab[j][k] = NULL;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	***ft_ultra_split(char *s, t_base *base)
{
	char	**tmp;
	char	***tab;

	(void)base;
	if (hm_pipe(s) == -1)
		return (NULL);
	tab = gc_alloc(sizeof(char ***) * (hm_pipe(s) + 2), 1);
	if (!tab)
		return (NULL);
	tmp = ft_super_split(s);
	if (!tmp)
		return (NULL);
	tab = ft_ultra_while(0, 0, tab, tmp);
	base->tablen = (hm_pipe(s) + 2);
	return (tab);
}

char	***build_tab(char *s, t_base *base)
{
	char	***tab;

	if (find_pipe(s) == -1)
		return (NULL);
	s = correct_input_for_parser(s);
	tab = ft_ultra_split(s, base);
	if (!tab)
		return (NULL);
	return (tab);
}

char	**process_tableau(char **tableau, t_base *base)
{
	char	**ret;
	int		j;
	int		k;
	char	*string;

	j = 0;
	k = 0;
	ret = gc_alloc(sizeof(char **) * ft_tablen(tableau) + 20, 2);
	while (tableau[j] != NULL)
	{
		if (tableau[j])
		{
			string = modif_token(tableau[j], base);
			if (!string)
				j++;
			else if (ft_strcmp(string, "\a\0") != 0)
			{
				ret[k] = string;
				k++;
			}
		}
		j++;
	}
	ret[k] = NULL;
	return (ret);
}

char	***gest_dollar_multipipe(t_base *base, int j)
{
	char	***ret;
	int		i;

	(void)j;
	i = -1;
	ret = gc_alloc(sizeof(char ***) * ft_triple_tablen(base->tableau) + 20, 2);
	while (base->tableau && base->tableau[++i])
	{
		ret[i] = process_tableau(base->tableau[i], base);
	}
	ret[i] = NULL;
	return (ret);
}
