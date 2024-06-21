/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:34:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 11:49:04 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_char(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

void	message(t_base *base)
{
	ft_putstr_fd("exit", base->fd_out);
	ft_putchar_fd('\n', base->fd_out);
	ft_putstr_fd("/-------------------", base->fd_out);
	ft_putchar_fd(92, base->fd_out);
	ft_putchar_fd('\n', base->fd_out);
	ft_putstr_fd("| Goodbye Minishell |\n", base->fd_out);
	ft_putchar_fd(92, base->fd_out);
	ft_putstr_fd("-------------------/\n", base->fd_out);
}

int	ft_super_tablen(char ***tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	exit_prog(int i, void *ptr, t_base *base)
{
	(void)base;
	if (1 == i)
	{
		message(base);
		free(ptr);
	}
}

int	basic_exit(t_base *base, int i, long long tmp, int ret)
{
	(void)ret;
	if (base->tablen < 2 && ft_tablen(base->tableau[i]) > 2
		&& ft_is_num(base->tableau[i][1]) == 1)
	{
		ft_putstr_fd("exit: too many arguments\n", base->fd_out);
		g_return_code = 2;
		return (-1);
	}
	if (base->tablen < 2 && ft_check_char(base->tableau[i][1]) == 0)
	{
		ft_putstr_fd("exit:", base->fd_out);
		ft_putstr_fd(base->tableau[i][1], base->fd_out);
		ft_putstr_fd(" numeric argument required\n", base->fd_out);
		tmp = 2;
	}
	else if (ft_check_char(base->tableau[i][1]) == 1)
		tmp = ft_atoi(base->tableau[i][1]);
	else if (ft_tablen(base->tableau[i]) == 2)
		tmp = ft_long_atoi(base->tableau[i][1]);
	if (base->tablen <= 1)
		message(base);
	free_base(base);
	gc_free_all();
	return (tmp);
}