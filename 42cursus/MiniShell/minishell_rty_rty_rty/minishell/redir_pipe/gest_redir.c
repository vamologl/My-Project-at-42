/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:49:03 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/16 15:33:07 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_exec(char **tab)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ret = gc_alloc(sizeof(char **) * (ft_tablen(tab) + 1), 2);
	if (!tab)
		return (NULL);
	while (tab && tab[i])
	{
		if (tab[i] && ft_find_redirection(tab[i]) != 0)
		{
			if (tab[i] && tab[i + 1] && tab[i + 2])
				i = i + 2;
			else if (!tab[i] || !tab[i + 1] || !tab[i + 2])
				break ;
		}
		else
			ret[j++] = ft_strdup_gc(tab[i++], 2);
	}
	ret[i] = NULL;
	return (ret);
}

void	multi_redir2(char **str, t_base *base, int j)
{
	while (*str)
	{
		if (ft_find_redirection(*str) == 1
			|| ft_find_redirection(*str) == 2)
		{
			set_output(str, base);
			base->fd_in = 0;
			break ;
		}
		else if (ft_find_redirection(*str) == 3)
		{
			ft_left_redir(str, base, j);
			base->fd_out = 1;
			break ;
		}
		else if (ft_find_redirection(*str) == 4)
		{
			ft_double_lredir(base, j);
			base->fd_out = 1;
			base->fd_in = 0;
			break ;
		}
		str++;
	}
}

void	multi_redir(char **str, t_base *base, int j)
{
	if (only_one_type_redir(str))
		multi_redir2(str, base, j);
	else
	{
		ft_double_lredir(base, j);
		if (base->error_parse == 0)
		{
			ft_left_redir(str, base, j);
			set_output(str, base);
		}
	}
}
