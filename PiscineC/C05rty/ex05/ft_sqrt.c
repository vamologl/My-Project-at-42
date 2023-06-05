/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:31:08 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/16 14:01:28 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	in;
	int	j;

	j = nb;
	if (j <= 0)
		return (0);
	if (j == 1)
		return (1);
	in = 2;
	if (j >= 2)
	{
		while (in * in <= j && in <= 46340)
		{
			if (in * in == j)
			{
				return (in);
			}
			in++;
		}
	}
	return (0);
}

/*#include<stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147483647));
	printf("%d\n", ft_sqrt(-2147483648));
	return(0);
}*/
