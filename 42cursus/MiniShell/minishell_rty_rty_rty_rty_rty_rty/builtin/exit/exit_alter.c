/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_alter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:25:20 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern volatile int	g_return_code;

void	ft_exit_alt2(t_base *base)
{
	int	tmp;

	tmp = 0;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return ;
	}
	if (tmp == -1)
	{
		g_return_code = 1;
		return ;
	}
	free_base(base);
	exit(tmp);
}

void	close_all(int mode)
{
	int	i;

	i = mode;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	ft_exit_alt(t_base *base, int i, int mode, int ret)
{
	int	tmp;

	tmp = 1;
	if (base->tableau[i][0] && !base->tableau[i][1])
		tmp = 0;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return ;
	}
	tmp = basic_exit(base, i, tmp, ret);
	if (tmp == -1)
	{
		if (ret == 131)
			g_return_code = 1;
		else
			g_return_code = ret;
		g_return_code = 1;
		return ;
	}
	close_all(0);
	if (mode == 1)
		exit(ret);
	exit(tmp);
}
