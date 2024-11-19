/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 11:01:00 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

extern volatile int	g_return_code;

void	reset_exec(t_base *base)
{
	base->info_signal = 0;
	base->tablen = 0;
	base->return_value_flag = 0;
	base->dl_redir = 0;
	base->dl_redir_check_break = 0;
	base->error_parse = 0;
	base->here_doc = 0;
	base->add_heredoc = 0;
	dup2(base->terminal_out, base->fd_out);
	dup2(base->terminal_in, base->fd_in);
}

void	ft_loop(t_base *base)
{
	while (1)
	{
		check_loop_start(base);
		base->input = readline(base->user);
		reset_exec(base);
		if (base->input == NULL)
			break ;
		add_history(base->input);
		if (check_parser(base->input, base) == 1)
			free(base->input);
		else
			parser(base);
	}
	message(base);
	close_all(0);
	ft_exit_alt2(base);
}

int	main(int ac, char **av, char **env)
{
	t_base	*base;

	(void) ac;
	(void) av;
	base = gc_alloc(sizeof(t_base), 8);
	base->pipe = gc_alloc(sizeof(t_pipeline), 8);
	init_base(base, env);
	set_signal_handlers();
	init_user(base);
	init_path(base);
	gest_shlvl(base);
	g_return_code = 0;
	ft_loop(base);
	rl_clear_history();
	ft_exit(base, 0);
	return (2);
}
