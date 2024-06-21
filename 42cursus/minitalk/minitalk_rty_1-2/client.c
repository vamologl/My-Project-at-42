/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:45:32 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/22 09:19:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	send_bits(char octet, int pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(150);
	}
}

void	stxt(int pid, char *tx)
{
	int	i;

	i = 0;
	while (tx[i])
		send_bits(tx[i++], pid);
}

void	schar(int pid, char c)
{
	unsigned char	octets;

	octets = c;
	send_bits(octets, pid);
}

int	main(int ac, char **av)
{
	t_clientstruct	client;

	if (ac == 3)
	{
		if (isnum(av[1]) == 1)
		{
			if (ft_atoi(av[1]) <= 0)
			{
				ft_printf("Erreur, PID invalide\n");
				return (-1);
			}
			client.pid = (ft_atoi(av[1]));
			schar(client.pid, 2);
			stxt(client.pid, av[2]);
			schar(client.pid, 3);
		}
		else
		{
			ft_printf("Erreur, PID invalide\n");
			exit(-2);
		}
	}
	else
		ft_printf("Erreur argument, ./client [PID] [Message]\n");
	return (0);
}
