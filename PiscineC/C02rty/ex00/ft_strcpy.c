/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:09:55 by vamologl          #+#    #+#             */
/*   Updated: 2023/04/12 13:34:21 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char	*dest, char *src)
{
	int		i;
	char	*c;

	i = 0;
	c = dest;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int	main(void)
{
	char	*str;
	char	*dst;

	str = "test";
	dst = (char *) malloc(50);
	printf("%s\n", ft_strcpy(dst, str));
	printf("%s\n", strcpy(dst, str));
	return (0);
}*/
