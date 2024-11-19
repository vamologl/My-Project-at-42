/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:34:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 13:44:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_char(char *s)
{
	int	i;

	i = 0;
	if (!s && ft_strlen(s) == 0)
		return (-1);
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s && s[i] == '-')
		i++;
	while (s && s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	while (s && s[i])
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

void	exit_prog(int i, void *ptr, t_base *base)
{
	(void)base;
	if (1 == i)
	{
		message(base);
		free(ptr);
	}
}

void	message_exit(t_base *base, int *i, long long *tmp, int mode)
{
	if (mode == 0)
	{
		ft_putstr_fd("exit: too many arguments\n", base->fd_out);
		g_return_code = 2;
	}
	if (mode == 1)
	{
		ft_putstr_fd("exit:", base->fd_out);
		ft_putstr_fd(base->tableau[(*i)][1], base->fd_out);
		ft_putstr_fd(" numeric argument required\n", base->fd_out);
		(*tmp) = 2;
	}
}

int	basic_exit(t_base *base, int i, long long tmp, int ret)
{
	(void)ret;
	if (base->tableau[i] && base->tableau[i][0] && base->tableau[i][1])
	{
		if (base->tablen < 2 && ft_tablen(base->tableau[i]) > 2
			&& ft_is_num(base->tableau[i][1]) == 1)
		{
			message_exit(base, 0, &tmp, 0);
			return (-1);
		}
		else if (base->tablen < 2 && ft_check_char(base->tableau[i][1]) == 0)
			message_exit(base, &i, &tmp, 1);
		else if (ft_check_char(base->tableau[i][1]) == 1
			&& ft_strlen(base->tableau[i][1]) != 0)
			tmp = ft_atoi(base->tableau[i][1]);
		else if (ft_tablen(base->tableau[i]) == 2)
			tmp = ft_atoi(base->tableau[i][1]);
	}
	if (base->tablen <= 1)
		message(base);
	free_base(base);
	gc_free_all();
	return (tmp);
}
