/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:55:37 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/23 10:39:51 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>


int	ft_ultimate_range(int **range, int min, int max)
{
	int	limit;
	int	i;
	int	*bfr;
	int	*d;

	i = 0;
	limit = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	d = (bfr = malloc(limit * sizeof(int)));
	if (!d)
	{
		*range = 0;
		return (-1);
	}
	*range = bfr;
	while (i < limit)
	{
		bfr[i] = min + i;
		i++;
	}
	return (limit);
}

int	main(void)
{
	int	max;
	int	min;
	int	size;
	int	i = 0;
	int	*j;

	min = -1273;
	max = 0;
	size = ft_ultimate_range(&j, min, max);
	while (i < size)
	{
		printf("%d\n", j[i]);
		i++;
	}
}
