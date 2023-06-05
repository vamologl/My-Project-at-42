/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:50:54 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/20 11:32:08 by vamologl         ###   ########.fr       */
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
	char	*dst1;

	dst = (dst1 =  (char *)malloc(ft_strlen(src) *sizeof(char) + 1));
	if (!dst1)
		return(0);
	while (src[i] != '\0')
	{
		src[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	free(dst1);
	return (dst);
}


int	main(void)
{
	char	*str;
	char 	*allocated;

	str = "test with malloc()";
	printf("original base : $%s$ @ %p\n", str, str);
	allocated = strdup(str);
	printf("copied alloc : $%s$ @ %p\n", allocated , allocated);
	allocated = ft_strdup(str);
	printf("ft_copied alloc : $%s$ @ %p\n", allocated, allocated);	
}
