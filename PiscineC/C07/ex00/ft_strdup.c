/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:50:54 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/22 09:59:02 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;
	char	*c;

	i = 0;
	c = ((dst =  (char *)malloc(ft_strlen(src)+ sizeof(char) + 1)));
	if (!c)
		return(0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


int	main(void)
{
	char	str[] = "tout fonctionne sans probleme";

	printf("%s\n", "le nombre de char a copier :");
	printf("%d\n", ft_strlen(str));
	printf("%s\n", "la fonction ft_strdup :");
	printf("%s\n", ft_strdup(str));
	printf("%s\n", "la fonction original strdup :");
	printf("%s\n", strdup(str));
	return (0);
}
