/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/28 15:29:52 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

extern volatile int	g_return_code;

void	received_signal(int n)
{
	int	flag;

	flag = 0;
	if (g_return_code == 131 || g_return_code == 132)
		flag = 1;
	if (n == SIGTSTP || n == SIGINT)
	{
		if (g_return_code != 132)
			printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		if (flag != 1)
			rl_redisplay();
		flag = 0;
		g_return_code = 130;
	}
	else if (n == SIGQUIT)
	{
		printf("\b\b  \b\b");
		if (flag != 1)
			rl_redisplay();
	}
}

void	set_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = received_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	reset_exec(t_base *base)
{
	base->info_signal = 0;
	base->tablen = 0;
	base->return_value_flag = 0;
	base->dl_redir = 0;
	base->dl_redir_check_break = 0;
	base->error_parse = 0;
	base->here_doc = 0;
}

void	ft_loop(t_base *base)
{
	while (1)
	{
		init_user(base);
		base->input = readline(base->user);
		reset_exec(base);
		if (base->input == NULL)
			break ;
		else if (is_empty(base->input) == 0 || chk_quote(base->input) != 1)
		{
			if (chk_quote(base->input) != 1)
				ft_putstr_fd("Error - Quotes are not closed\n", base->fd_out);
			free(base->input);
		}
		else
		{
			add_history(base->input);
			parser(base);
		}
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
