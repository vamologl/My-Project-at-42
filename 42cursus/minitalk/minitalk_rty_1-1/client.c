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
	int				nbchar;
	unsigned char	octets;

	i = 0;
	nbchar = 0;
	while (tx[i] != '\0')
	{
		octets = tx[i];
		print_bits(octets, pid);
		i++;
		nbchar++;
	}
}

void	schar(int pid, char c)
{
	unsigned char	octets;

	octets = c;
	print_bits(octets, pid);
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
		schar(pid, 12);
	}
	else
		ft_printf("Erreur argument\n");
	return (0);
}
