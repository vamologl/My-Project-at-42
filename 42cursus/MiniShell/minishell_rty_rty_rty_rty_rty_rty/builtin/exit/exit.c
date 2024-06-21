/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:02 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:26:16 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_gc_free(void)
{
	gc_free_p(1);
	gc_free_p(2);
	gc_free_p(3);
	gc_free_p(5);
	gc_free_p(6);
	gc_free_p(4);
	gc_free_p(-1);
	gc_free_p(8);
	gc_free_p(7);
	gc_free_p(9);
}

void	free_base(t_base *base)
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

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_base *base, int i)
{
	long long	tmp;

	tmp = 0;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return ;
	}
	tmp = basic_exit(base, i, tmp, 0);
	if (tmp == -1)
	{
		g_return_code = 1;
		return ;
	}
	close_all(0);
	free(base->input);
	exit(tmp);
}
