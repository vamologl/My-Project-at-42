/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:16:42 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/06 11:39:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include<stdio.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

/*int	main(void)
{
	int	c;
	int	d;
	int	*e = &c;
	int	*m = &d;

	c = 8;
	d = 4;
	ft_div_mod(c, d, e, m);
	printf("%d\n", *e);
	printf("%d\n", *m);
	return (0);
}*/
