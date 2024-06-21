/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:45:32 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 11:30:23 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
/*
void	print_bits(unsigned char octet, int pid)
{
	int		oct;
	int		div;

	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			kill(pid, SIGUSR2);
			oct = oct % div;
			usleep(1);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(1);
		}
		div = div / 2;
	}
}

void	stxt(int pid, char *tx)
{
	int				i;
	unsigned char	octets; 

	i = 0;
	while (tx[i] != '\0')
	{
		octets = tx[i];
		print_bits(octets, pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 0)
		{
			ft_printf("Erreur, argument < 0\n");
			return (-1);
		}
		pid = (ft_atoi(av[1]));
		stxt(pid, av[2]);
	}
	else
		ft_printf("Erreur argument\n");
	return (0);
}*/

#include "include/minitalk.h"

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Erreur, ./client <PID> <Message>");
		return (1);
	}
	return (0);
}
