/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:54:23 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/02 13:44:56 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char ch1)
{
	write(1, &ch1, 1);
}

void	ft_putchar_m(int c1, int c2, int c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
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

	i1 = '0';
	i2 = '1';
	i3 = '2';
	while (i1 <= '7')
	{
		i2 = i1 + 1;
		while (i2 <= '8')
		{
			i3 = i2 + 1 ;
			while (i3 <= '9')
			{
				ft_putchar_m(i1, i2, i3);
				i3++;
			}
			i2++;
		}
		i1++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
