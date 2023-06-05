/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:19:27 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/21 16:03:59 by vamologl         ###   ########.fr       */
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

	j = argc - 1;
	while (j > 0)
	{
		ft_putstr(argv[j]);
		ft_putstr("\n");
		j--;
	}
	return (0);
}
