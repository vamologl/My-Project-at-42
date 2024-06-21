/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:48:42 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/03 15:15:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	remove_old_env(t_base *base, char *var_name)
{
	int	i;

	i = 0;
	while (base->env_old[i])
	{
		if (ft_strncmp(var_name, base->env_old[i],
				ft_strclen(var_name, '=')) == 0)
		{
			base->env_old[i] = ft_strjoin_gc("\a", "\0", -1);
			return ;
		}
		i++;
	}
}

void	ft_unset(t_base *base, int j)
{
	int	i;

	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	i = 1;
	while (base->tableau[j][i])
	{
		remove_old_env(base, base->tableau[j][i]);
		i++;
	}
}
