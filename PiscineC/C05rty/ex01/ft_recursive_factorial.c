/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:28 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/20 13:54:18 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	else if (nb > 0)
	{
		i = nb * ft_recursive_factorial(nb - 1);
		nb -= 1;
	}
	return (i);
}

/*#include<stdio.h>
int	main(void)
{
	printf("%i\n", ft_recursive_factorial(-16));
	printf("%i\n", ft_recursive_factorial(0));
	printf("%i\n", ft_recursive_factorial(1));
	printf("%i\n", ft_recursive_factorial(2));
	printf("%i\n", ft_recursive_factorial(12));
	printf("%i\n", ft_recursive_factorial(3));
	printf("%i\n", ft_recursive_factorial(4));
	printf("%i\n", ft_recursive_factorial(5));
	printf("%i\n", ft_recursive_factorial(6));
	printf("%i\n", ft_recursive_factorial(7));
	printf("%i\n", ft_recursive_factorial(8));
	printf("%i\n", ft_recursive_factorial(10));
	printf("%i\n", ft_recursive_factorial(11));
}*/
