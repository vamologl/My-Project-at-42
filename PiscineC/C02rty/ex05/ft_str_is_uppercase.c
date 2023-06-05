/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:25:04 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/09 13:45:37 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
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
	printf("%d\n", ft_str_is_uppercase("test"));
	printf("%d\n", ft_str_is_uppercase("TEST"));
	printf("%d\n", ft_str_is_uppercase("0123"));
	return (0);
}*/
