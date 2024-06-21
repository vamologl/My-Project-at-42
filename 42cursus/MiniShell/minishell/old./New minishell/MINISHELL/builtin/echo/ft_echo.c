/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/30 15:29:01 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	write_echo_alt(t_base *base, int i, int flag, int k)
{
	while (base->tableau[k][i])
	{
		echo_putstr_fd(base->tableau[k][i], base->fd_out);
		if (base->tableau[k][i + 1])
			ft_putchar_fd(' ', base->fd_out);
		i++;
	}
	if (flag == 0)
		ft_putchar_fd('\n', base->fd_out);
}

void	echo_else(t_base *base, int *i, int *k, int *flag)
{
	int	j;

	j = 0;
	if (base->tableau[(*k)][(*i)][j] == '-')
	{
		j++;
		while (base->tableau[(*k)][(*i)][j] == 'n')
			j++;
		if (base->tableau[(*k)][(*i)][j] == '\0')
		{
			(*flag) = 1;
			(*i)++;
		}
	}
}

void	own_echo(t_base *base, int k)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 1;
	j = 0;
	if (base->tableau[k][0] && !base->tableau[k][1])
	{
		write_echo(base, k);
		base->return_value = 1;
		return ;
	}
	else
		echo_else(base, &i, &k, &flag);
	write_echo_alt(base, i, flag, k);
	base->return_value = 0;
}
