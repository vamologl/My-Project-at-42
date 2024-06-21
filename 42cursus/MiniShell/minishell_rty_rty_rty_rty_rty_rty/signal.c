/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:57:12 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 13:43:04 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

extern volatile int	g_return_code;

void	received_signal2(int flag)
{
	if (flag != 1)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
		g_return_code = 131;
	}
	if (flag == 1)
	{
		printf("\b\b");
		printf("^\\Quit (core dumped)\n");
		g_return_code = 131;
	}
}

void	received_signal(int n)
{
	int	flag;

	flag = 0;
	if (g_return_code == 134 || g_return_code == 132)
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
		received_signal2(flag);
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
