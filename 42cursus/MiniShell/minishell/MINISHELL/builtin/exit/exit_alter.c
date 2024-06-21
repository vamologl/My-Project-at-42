/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_alter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/03 15:29:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return ;
	}
	basic_exit(base, i, tmp);
	free(base->input);
	exit(tmp);
}
