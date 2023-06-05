/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:28 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/14 16:07:22 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	r;

	r = 1;
	if (r > 0)
	{
		r *= r * ft_recursive_factorial(nb -1);
		nb -= 1;
	}
	if (nb < 0)
		return (0);
	return (r);
}

#include<stdio.h>

int	main(void)
{
	printf("%i", ft_recursive_factorial(5));
}
