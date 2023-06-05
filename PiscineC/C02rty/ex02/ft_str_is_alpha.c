/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:58:41 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/09 13:40:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
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
	printf("%d\n", ft_str_is_alpha("test"));
	printf("%d\n", ft_str_is_alpha("TEST"));
	printf("%d\n", ft_str_is_alpha("123"));
	return (0);
}*/
