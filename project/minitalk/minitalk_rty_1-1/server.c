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
		g_receive = -2;
}

char	receive_byte(void)
{
	char	c;
	int		count;
	unsigned char	*msg = NULL;

	c = 0;
	count = 0;
	while (1)
	{
		while (g_receive == -1)
			continue ;
		c += g_receive;
		g_receive = -1;
		if (++count == 8)
		{
			//write(1, &c, 1);
			ft_strjoin(msg, &c)
		}
		else
			c <<= 1;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				c;
	char				*memo;
	int					i;

	i = 0;
	memo = (char *)malloc(sizeof(char *) + 42);
	ft_printf("Server PID: %u\n", getpid());
	sa.sa_handler = received_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		c = receive_byte();
		if (!c)
		{
			write(1, "|empty|", 7);
		}
		else if (c == 12)
		{
			memo[i] = '\0';
			ft_printf("%s", memo);
			ft_printf("|i = %d|", i);
			//free(memo);
			memo = (char *)malloc(sizeof(char *) + 42);
			i = 0;
		}
		else if (g_receive == -2)
		{
			free(memo);
			ft_printf("non");
			exit(-1);
			return (-1);
		}
		else if (ft_isprint(c))
		{
			if ((i + 1) >= (i + 42))
			 	memo = (char *)malloc(sizeof(char *) + (i + 42));
			memo[i] = c;
			i++;
		}
	}
	free(memo);
}
