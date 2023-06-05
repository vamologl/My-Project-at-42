/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:10:42 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/14 13:16:23 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *scr, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (scr[j] != '\0' && j < nb)
	{
		dest[i] = scr[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include<stdio.h>

int	main(void)
{
	char	c[] = "012345";
	char	d[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("%s\n", ft_strncat(c, d, 10));
	return (0);
}*/
