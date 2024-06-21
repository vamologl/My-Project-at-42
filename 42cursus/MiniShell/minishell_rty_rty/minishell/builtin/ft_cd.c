/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:23:48 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/03 15:29:30 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	own_cd2(char **s, t_base *base, int x)
{
	DIR	*tmp;

	x = chdir(s[1]);
	tmp = opendir(s[1]);
	if (!tmp)
	{
		if (x == -1)
		{
			base->return_value = 1;
			perror(s[1]);
			return ;
		}
	}
	free(tmp);
	base->return_value = 0;
}

void	own_cd3(t_base *base)
{
	ft_putstr_fd("cd : to many argument\n", base->fd_out);
	base->return_value = 1;
	return ;
}

void	own_cd4(char *str, t_base *base)
{
	int		x;
	char	**s;
	char	*to_free;

	s = ft_split_gc(str, ' ', 2);
	if (s[1] == NULL)
	{
		to_free = get_var_env(base->env_old, "HOME=");
		x = chdir(to_free);
	}
	if (ft_tablen(s) > 2)
	{
		own_cd3(base);
		return ;
	}
	else if (s[1] != NULL)
	{
		own_cd2(s, base, x);
		return ;
	}
}

void	own_cd(char *str, t_base *base)
{
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	own_cd4(str, base);
	base->return_value = 0;
}
