/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:30:16 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/10 10:17:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*include<stdio.h>

int	main(void)
{
	char	ch[] = "test";
	char	ch1[] = "TEST";
	char	ch2[] = "0123";

	printf("%s\n", ft_strlowercase(ch));
	printf("%s\n", ft_strlowercase(ch1));
	printf("%s\n", ft_strlowercase(ch2));
	return (0);
}*/
