/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_alter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/13 11:45:48 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_all(int mode)
{
	int i;

	i = mode;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	free_base_alt(t_base *base)
{
	if (base->output_file)
		free(base->output_file);
	if (base->command)
		free(base->command);
	close(base->terminal_in);
	close(base->terminal_out);
	close(base->fd_out);
	close(base->fd_in);
	rl_clear_history();
	ft_gc_free();
}

void	ft_exit_alt(t_base *base, int i)
{
	int	tmp;

	tmp = 1;
	if (!base->tableau[i][1])
		tmp = 0;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	tmp = basic_exit(base, i, tmp);
	if (tmp == -1)
	{
		base->return_value = 1;
		return ;
	}
	close_all(0);
	exit(tmp);
}
