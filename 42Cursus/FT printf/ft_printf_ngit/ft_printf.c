/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:56:41 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/02 15:03:26 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_one_char(const char *c)
{
	write(1, &c, 1);
}

void	print_string(const char *c)
{
	while (c)
		write(1, &c, 1);
		c++;
}

void	print_pourcent(const char *c)
{
	write(1, '%', 1);
}
