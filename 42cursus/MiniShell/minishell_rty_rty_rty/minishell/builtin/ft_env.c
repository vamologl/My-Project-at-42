/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:13 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/20 10:40:01 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	own_env_else(t_base *base, int j)
{
	while (base->env_old[j])
	{
		if (!base->env_old[j])
			j++;
		else
		{
			if (is_there_char(base->env_old[j], '=') == 1)
			{
				ft_putstr_fd(base->env_old[j], base->fd_out);
				ft_putstr_fd("\n", base->fd_out);
			}
			j++;
		}
	}
	base->return_value = 0;
}

void	own_env(t_base *base, int i)
{
	int	j;

	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	j = 0;
	if (base->tableau && base->tableau[i][0])
	{
		if (base->tableau[i][1])
		{
			ft_putstr_fd("env: ", base->fd_out);
			ft_putstr_fd(base->tableau[i][1], base->fd_out);
			ft_putstr_fd(": No such file or directory\n", base->fd_out);
			base->return_value = 127;
			return ;
		}
		else
			own_env_else(base, j);
		return ;
	}
	perror("ERROR: env");
}
