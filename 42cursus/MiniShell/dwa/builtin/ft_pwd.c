/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:52:50 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/29 10:29:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_pwd(t_base *base, int mode)
{
	char	tmp[PATH_MAX];

	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return (130);
	}
	if (getcwd(tmp, PATH_MAX))
	{
		base->cur_pwd = return_pwd();
		if (mode != 1)
		{
			ft_putstr_fd(base->cur_pwd, base->fd_out);
			ft_putchar_fd('\n', base->fd_out);
		}
		g_return_code = 0;
		return (1);
	}
	g_return_code = 0;
	return (0);
}

char	*return_pwd(void)
{
	static char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		return (cwd);
	else
	{
		perror("getcwd() error");
		return (NULL);
	}
}
