/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:59:41 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/06 09:48:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include<stdio.h>*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}

/*int	main(void)
{
	int	i1;
	int 	i2;

	i1 = 8;
	i2 = 4;
	ft_ultimate_div_mod(&i1, &i2);
	printf("%d\n", i1);
	printf("%d\n", i2);
}*/
