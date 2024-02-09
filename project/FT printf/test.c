/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:54:33 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/05 13:52:37 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	c[] = "abcdefghijklmnopqrstuvwxyz";

	printf("%s", c);
	printf("%c", '\n');
	ft_printf("%s", c);
	return (0);
}
