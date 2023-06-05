/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:46:05 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/09 14:03:08 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
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
	printf("%d\n", ft_str_is_printable("TESTtest023456789%#"));
	printf("%d\n", ft_str_is_printable("\n\t\v\f"));
	return (0);
}*/
