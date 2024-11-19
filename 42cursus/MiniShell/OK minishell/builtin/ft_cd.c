/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:48 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/31 10:07:36 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	own_cd2(int k, t_base *base, int x)
{
	DIR		*tmp;
	char	*strtmp;

	tmp = opendir(base->tableau[k][1]);
	if (!tmp)
	{
		if (x == -1)
		{
			perror(base->tableau[k][1]);
			return (1);
		}
	}
	else
	{
		strtmp = ft_strjoin_gc("OLDPWD=", return_pwd(), 2);
		update_env_old(base, strtmp);
		x = chdir(base->tableau[k][1]);
		strtmp = ft_strjoin_gc("PWD=", return_pwd(), 2);
		update_env_old(base, strtmp);
	}
	free(tmp);
	return (0);
}

void	own_cd3(t_base *base)
{
	ft_putstr_fd("cd : too many argument\n", base->fd_out);
	g_return_code = 1;
	return ;
}

void	own_cd4(int k, t_base *base)
{
	int		x;
	char	*to_free;
	char	*strtmp;

	x = -1;
	if (base->tableau[k][1] == NULL)
	{
		to_free = get_var_env(base->env_old, "HOME=");
		x = chdir(to_free);
		strtmp = ft_strjoin_gc("PWD=", return_pwd(), 2);
		update_env_old(base, strtmp);
	}
	if (ft_tablen(base->tableau[k]) > 2)
	{
		own_cd3(base);
		return ;
	}
	else if (base->tableau[k][1] != NULL)
	{
		g_return_code = own_cd2(k, base, x);
		return ;
	}
}

void	own_cd(int k, t_base *base)
{
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return ;
	}
	g_return_code = 0;
	own_cd4(k, base);
}
