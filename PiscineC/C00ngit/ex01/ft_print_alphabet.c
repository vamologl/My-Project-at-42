/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:32:08 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/01 09:59:39 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	ft_print_alphabet(char c)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}

int	main(void)
{
	ft_print_alphabet('n');
	return (0);
}
