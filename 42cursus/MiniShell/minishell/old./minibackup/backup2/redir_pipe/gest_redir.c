/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:49:03 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/22 15:03:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_exec2(char **tab, char **ret, int i, int j)
{
	int	k;

	k = 0;
	ret = (char **)gc_alloc(sizeof(char *) * (j - i + 1), 2);
	if (!ret)
	{
		perror("get_exec");
		return (NULL);
	}
	while (i < j)
	{
		ret[k] = ft_strdup_gc(tab[i], 2);
		i++;
		k++;
	}
	ret[k] = NULL;
	return (ret);
}

char	**get_exec(char **tab)
{
	char	**ret;
	int		k;
	int		i;
	int		j;

	i = 0;
	k = 0;
	ret = NULL;
	if (!tab)
		return (NULL);
	while (tab[i] && ft_find_redirection(tab[i]) != 0)
		i += 2;
	j = i;
	while (tab[j] && ft_find_redirection(tab[j]) == 0)
		j++;
	ret = get_exec2(tab, ret, i, j);
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
			set_input(str, base);
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
		set_input(str, base);
		set_output(str, base);
	}
}