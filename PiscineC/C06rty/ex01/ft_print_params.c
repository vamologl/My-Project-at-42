/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:55 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/21 15:57:22 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
}

int	main(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		ft_putstr("\n");
		j++;
	}
	return (0);
}
