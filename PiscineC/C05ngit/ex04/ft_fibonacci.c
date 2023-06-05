/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:05:46 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:41 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (0);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1)+ ft_fibonacci(index - 2));
}

#include<stdio.h>

int	main(void)
{
	int	i;

	i = 15;
	printf("%d\n", ft_fibonacci(i));
}
