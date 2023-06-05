/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:24:11 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/14 16:39:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb,int power)
{
	int	r;

	r = nb;
	while (power > 1)
	{
		r *= nb;
		power--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (r);
}

#include<stdio.h>

int	main(void)
{
	int	nb;
	int	rslt;

	nb = 2;
	rslt = 8;
	printf("%d\n", ft_iterative_power(nb, rslt));
}
