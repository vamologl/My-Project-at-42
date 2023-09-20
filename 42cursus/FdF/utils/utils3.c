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

float   maxim(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
	//return (a > b ? a : b);
}

float   mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
    //return (i < 0) ? -i : i;
}

int		set_color(int z)
{
	if (z != 0)
		return (0xbc00ff);
	else
		return (0x6f6f6f);
}