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

	ft_printf("Server PID: %u\n", getpid());
	sa.sa_handler = received_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		c = receive_byte();
		if (!c)
			write(1, "\n", 1);
		else if (ft_isprint(c))
			write(1, &c, 1);
	}
}
