/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:18:22 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/15 13:21:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace(char *str, int *ptr_i)
{	
	int	j;
	int	i;

	j = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			j *= -1;
		i++;
	}
	*ptr_i = i;
	return (j);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = whitespace(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

/*#include<stdio.h>
int	main(void)
{
	char	c[] = "   ---+--+1234ab567";

	printf("%d\n", ft_atoi(c));
	return (0);
}*/
