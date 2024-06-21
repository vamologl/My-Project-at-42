/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:10 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/07 14:16:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	***ft_ultra_while(int j, int k, char ***tab, char **tmp)
{
	int	i;

	i = 0;
	while (tmp && i < ft_tablen(tmp))
	{
		tab[j] = gc_alloc(sizeof(char **) * (tablen_pipe(tmp, i) + 1), 3);
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

char	*check_last_pipe(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != '|')
	{
		ret = malloc(sizeof(char) * (i + 3));
		ret = ft_strdup(s);
		ret[i] = ' ';
		ret[i + 1] = '|';
		ret[i + 2] = '\0';
		return (ret);
	}
	else
		return (s);
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

char	***gest_dollar_multipipe(t_base *base, int j)
{
	char	***ret;
	int		i;
	int		k;

	i = -1;
	ret = gc_alloc(sizeof(char ***) * ft_triple_tablen(base->tableau) + 20, 2);
	while (base->tableau && base->tableau[++i])
	{
		k = 0;
		j = 0;
		ret[i] = gc_alloc(sizeof(char **) * ft_tablen(base->tableau[i])
				+ 20, 2);
		while (base->tableau && base->tableau[i][j] != NULL)
		{
			if (ft_strcmp(modif_token(base->tableau[i][j], base), "\a\0") != 0)
			{
				ret[i][k] = modif_token(base->tableau[i][j], base);
				k++;
			}
			j++;
		}
		ret[i][k] = NULL;
	}
	ret[i] = NULL;
	return (ret);
}
