/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/08 11:19:25 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

extern volatile int	g_signal;

void	received_signal(int n)
{
	int	flag;

	flag = 0;
	if (g_signal == SIGUSR2)
		n = SIGQUIT;
	if (n == SIGTSTP || n == SIGINT)
	{
		if (g_signal != 0)
			flag = 1;
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		if (flag != 1)
			rl_redisplay();
		flag = 0;
		g_signal = 0;
	}
	else if (n == SIGQUIT)
	{
		if (g_signal != 0 && g_signal != SIGUSR2)
			flag = 1;
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
	g_signal = 0;
	base->tablen = 0;
	base->return_value_flag = 0;
	base->dl_redir = 0;
	base->dl_redir_check_break = 0;
	base->error_parse = 0;
}

void	ft_loop(t_base *base)
{
	while (1)
	{
		if (g_signal == SIGUSR2)
			wait(0);
		reset_exec(base);
		base->input = readline(base->user);
		if (base->input == NULL)
			break ;
		else if (is_empty(base->input) == 0)
			free(base->input);
		else if (chk_quote(base->input) != 1)
		{
			ft_putstr_fd("Error - Quotes are not closed\n", base->fd_out);
			free(base->input);
		}
		else
		{
			base->loop++;
			add_history(base->input);
			parser(base);
		}
	}
	ft_exit(base, 2);
}

int	main(int ac, char **av, char **env)
{
	t_base	*base;

	(void) ac;
	(void) av;
	g_signal = 0;
	set_signal_handlers();
	base = gc_alloc(sizeof(t_base), 8);
	base->pipe = gc_alloc(sizeof(t_pipeline), 8);
	init_base(base, env);
	init_user(base);
	gest_shlvl(base);
	ft_loop(base);
	rl_clear_history();
	ft_exit(base, 0);
	return (2);
}
