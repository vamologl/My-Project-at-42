/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:10:12 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 11:33:47 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
/*
static int	g_receive = -1;
static int	g_signal_pid = -1;

void	received_signal(int n)
{
	if (n == SIGUSR1)
		g_receive = 0;
	else if (n == SIGUSR2)
		g_receive = 1;
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

int	main(void)
{
	char				c;
	struct sigaction	sa;
	int 	sigreset;

	ft_printf("Server PID: %u\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = received_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		while(sigreset != 1)
		{
			c = receive_byte();
			if (!c)
				write(1, "\n", 1);
			else if (ft_isprint(c))
				write(1, &c, 1);
		}
		sigreset = 1;
	}
}*/

#include "include/minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		//ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Erreur, juste ./server <PID>");
		return (0);
	}
	pid = getpid();
	ft_printf("PID = %d", pid);
	sig.sa_sigaction = ft_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
