/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:11:03 by vamologl          #+#    #+#             */
/*   Updated: 2023/06/27 10:11:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	maxim(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	set_color(int z)
{
	if (z != 0)
		return (0xffffff);
	else
		return (0x40BBF8);
}

void	ft_bzero(void *s, int n)
{
	unsigned char	*c;
	int			i;

	c = s;
	i = 0;
	while (i++ < n)
		*c++ = 0;
}
