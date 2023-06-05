/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:37:35 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/06 11:37:51 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include<stdio.h>*/

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*int	main(void)
{
	int	i;
	int	j;

	i = 4;
	j = 8;
	ft_swap(&i, &j);
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}*/
