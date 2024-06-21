/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:19:40 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:53:02 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	echo_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s && s[i])
		{
			if (s[i + 1] && s[i] && s[i] == ' '
				&& (s[i + 1] == '|'
					|| s[i + 1] == '<' || s[i + 1] == '>'))
				i++;
			else if (i >= 1 && s[i] && s[i] == ' '
				&& s[i - 1] && (s[i - 1] == '|'
					|| s[i - 1] == '>' || s[i - 1] == '<'))
				i++;
			else
			{
				write(fd, &s[i], 1);
				i++;
			}
		}
	}
}

void	write_echo(t_base *base, int k)
{
	if (base->tableau[k][0] && !base->tableau[k][1])
	{
		ft_putchar_fd('\n', base->fd_out);
		return ;
	}
}

void	write_echo_alt(t_base *base, int i, int flag, int k)
{
	while (base->tableau[k][i])
	{
		if (is_string_printable(base->tableau[k][i]) != 0)
		{
			if (ft_strcmp("\a\0", base->tableau[k][i]) != 0)
				echo_putstr_fd(base->tableau[k][i], base->fd_out);
		}
		if (base->tableau[k][i + 1]
			&& ft_strcmp("\a\0", base->tableau[k][i + 1]) != 0)
		{
			if (ft_strcmp("\a\0", base->tableau[k][i]) == 0 && i == 1)
				echo_putstr_fd("", base->fd_out);
			else
				echo_putstr_fd(" ", base->fd_out);
		}
		i++;
	}
	if (flag == 0)
		ft_putchar_fd('\n', base->fd_out);
}
