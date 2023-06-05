/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:28 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/20 12:15:39 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		i = nb * ft_recursive_factorial(nb - 1);
	return (i);
}

/*#include<stdio.h>
int	main(void)
{
	printf("%i", ft_recursive_factorial(3));
}*/
