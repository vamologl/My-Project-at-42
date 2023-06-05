/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print-comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:54:23 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/01 12:33:37 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char ch1)
{
	write(1, &ch1, 1);
}

void	ft_putchar_m(char c1, char c2, char c3)
{
       	ft_putchar(c1 + 48);
       	ft_putchar(c2 + 48);
      	ft_putchar(c3 + 48);
	if (!(c1 == '7' && c2 == '8' && c3 == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	i1;
	int	i2;
	int	i3;

	while (i1 <= 7)
	{
		i2 = i1 + 1;
		while (i2 <= 8)
		{
			i3 = i2 + 1 ;
			while (i3 <= 9)
			{
				ft_putchar_m(i1, i2, i3);
				i3++;
			}
			i2++;
		}
		i1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
