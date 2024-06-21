/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:10:12 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/17 09:10:55 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static int	g_receive = -1;

void	received_signal(int n)
{
	if (n == SIGUSR1)
		g_receive = 0;
	else if (n == SIGUSR2)
		g_receive = 1;
	else if (n == SIGINT)
		exit (12);
}

void	gest_param(t_minitalk *mini, int param)
{
	if (param == 1)
	{
		mini->str = (char *)malloc(sizeof(char) + 1);
		mini->stor = (char *)malloc(sizeof(char) + 1);
		ft_bzero(mini->str);
	}
	else if (param == 2)
	{
		if (g_receive == 12)
			end_str(mini->str, mini->stor);
	}
}

char	receive_byte(void)
{
	char	c;
	int		count;

	c = 0;
	count = 0;
	while (1)
	{
		while (g_receive == -1)
			continue ;
		c += g_receive;
		g_receive = -1;
		if (++count == 8)
			return (c);
		else
			c <<= 1;
	}
}

void	manage(t_minitalk mini)
{
	static char		c;

	while (1)
	{
		if (g_receive == 12)
			c = 3;
		if (c == 2)
			gest_param(&mini, 1);
		c = 0;
		c = receive_byte();
		if (ft_isprint(c))
		{
			if (ft_strlen(mini.str) == 15)
			{
				mini.stor = ft_strjoin(mini.stor, mini.str);
				ft_bzero(mini.str);
			}
			mini.str = ft_strjoin(mini.str, &c);
		}
		else if (c == 3)
			end_str(mini.str, mini.stor);
	}
}

int	main(int ac, char **av)
{
	t_minitalk	mini;

	(void)av;
	if (ac > 1)
	{
		ft_printf("Erreur, trop d'argument");
		exit(1);
	}
	ft_printf("Server PID: %u\n", getpid());
	mini.sa.sa_handler = received_signal;
	sigemptyset(&mini.sa.sa_mask);
	mini.sa.sa_flags = 0;
	sigaction(SIGUSR1, &mini.sa, NULL);
	sigaction(SIGUSR2, &mini.sa, NULL);
	sigaction(SIGINT, &mini.sa, NULL);
	manage(mini);
}
