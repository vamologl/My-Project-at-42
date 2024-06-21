/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_alter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/26 15:38:23 by vamologl         ###   ########.fr       */
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
	if (i == 2)
	{
		message(base);
		free_base(base);
		exit(tmp);
	}
	if (base->tablen < 2 && ft_tablen(base->tableau[i]) > 2
		&& ft_is_num(base->tableau[i][1]) == 1)
	{
		ft_putstr_fd("exit: too many arguments\n", base->fd_out);
		return ;
	}
	if (base->tablen < 2 && ft_check_char(base->tableau[i][1], base) == 2)
		tmp = 2;
	else if (ft_tablen(base->tableau[i]) == 2)
		tmp = ft_atoi(base->tableau[i][1]);
	if (base->tablen <= 1)
		message(base);
	free_base_alt(base);
	gc_free_all();
	exit(tmp);
}
