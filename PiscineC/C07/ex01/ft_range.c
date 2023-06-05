/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:32 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/23 09:41:54 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	r;
	int	i;
	int	*bfr;
	int	*d;

	i = 0;
	r = max - min;
	d = (bfr = malloc(r * sizeof(int)));
	if (min >= max)
	{
		return ('\0');
	}
	if (!d)
	{
		return ('\0');
	}
	while (i < r)
	{
		bfr[i] = min + i;
		i++;
	}
	return (bfr);
}

/*
int	main(void)
{
	int	max;
	int	min;
	int	size;
	int	i = 0;
	int	*j;

	min = 2147483600;
	max = 2147483647;
	size = max - min;
	j = ft_range(min, max);
	while (i < size)
	{
		printf("%d\n", j[i]);
		i++;
	}
}*/
