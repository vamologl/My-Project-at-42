/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:56:18 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/09 13:57:13 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}	
		else
		{
			i++;
		}
	}
	return (1);
}

/*#include<stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_numeric("test"));
	printf("%d\n", ft_str_is_numeric("TEST"));
	printf("%d\n", ft_str_is_numeric("0123"));
	return (0);
}*/
