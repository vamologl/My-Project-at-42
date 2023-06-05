/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:17:48 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/14 12:49:31 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include<stdio.h>

int	main(void)
{
	char	*c;
	char	*c1;
	char	*c2;
	char	*c3;

	c = "a";
	c1 = "b";
	c2 = "1";
	c3 = "2";

	printf("%d\n", ft_strcmp(c, c1));
	printf("%d\n", ft_strcmp(c1, c));
	printf("%d\n", ft_strcmp(c2, c3));
	printf("%d\n", ft_strcmp(c3 ,c2));
	return (0);
}*/
