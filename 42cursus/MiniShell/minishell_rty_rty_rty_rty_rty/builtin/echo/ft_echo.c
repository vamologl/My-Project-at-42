/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/06 14:50:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_string_printable(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] >= 32 && s[i] <= 126)
			i++;
		else
		{
			return (0);
		}
	}
	if (s && s[0] != '\0')
	{
		return (1);
	}
	return (0);
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

void	echo_else(t_base *base, int *i, int *k, int *flag)
{
	int	j;

	while (base->tableau[(*k)][(*i)] && base->tableau[(*k)][(*i)][0] == '-')
	{
		j = 1;
		while (base->tableau[(*k)][(*i)][j] == 'n')
			j++;
		if (base->tableau[(*k)][(*i)][j] == '\0' && j != 1)
			(*flag) = 1;
		else
			break ;
		(*i)++;
	}
}

void	own_echo(t_base *base, int k)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return ;
	}
	if (base->tableau[k][0] && !base->tableau[k][1])
	{
		write_echo(base, k);
		g_return_code = 0;
		return ;
	}
	else
		echo_else(base, &i, &k, &flag);
	write_echo_alt(base, i, flag, k);
	g_return_code = 0;
}
