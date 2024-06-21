/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:40:44 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/16 09:40:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	isnum(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		else
			i++;
	}
	return (1);
}

void	ft_bzero(void *s)
{
	unsigned char	*c;

	c = s;
	while (*c != '\0')
		*c++ = 0;
}

void	end_str(char *str, char *stor)
{
	stor = ft_strjoin(stor, str);
	ft_printf("%s\n", stor);
	ft_bzero(str);
	ft_bzero(stor);
	free(str);
	free(stor);
}
