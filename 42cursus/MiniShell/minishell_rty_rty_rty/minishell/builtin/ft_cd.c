/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:48 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/16 10:16:25 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	own_cd2(int k, t_base *base, int x)
{
	DIR	*tmp;

	x = chdir(base->tableau[k][1]);
	tmp = opendir(base->tableau[k][1]);
	if (!tmp)
	{
		if (x == -1)
		{
			perror(base->tableau[k][1]);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

void	own_cd3(t_base *base)
{
	ft_putstr_fd("cd : too many argument\n", base->fd_out);
	base->return_value = 1;
	return ;
}

void	own_cd4(int k, t_base *base)
{
	int		x;
	char	*to_free;

	if (base->tableau[k][1] == NULL)
	{
		to_free = get_var_env(base->env_old, "HOME=");
		x = chdir(to_free);
	}
	if (ft_tablen(base->tableau[k]) > 2)
	{
		own_cd3(base);
		return ;
	}
	else if (base->tableau[k][1] != NULL)
	{
		base->return_value = own_cd2(k, base, x);
		return ;
	}
}

void	own_cd(int k, t_base *base)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	own_cd4(k, base);
}
