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
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

float	mod(float i)
{
	if (i < 0)
	{
		i = 0;
	}
	if (i < 0)
	{
		return (-i);
	}
	else
	{
		return (i);
	}
}
