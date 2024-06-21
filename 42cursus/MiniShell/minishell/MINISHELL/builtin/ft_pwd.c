/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:52:50 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/03 15:17:30 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_pwd(t_base *base)
{
	char	tmp[PATH_MAX];

	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		base->return_value = 130;
		return (130);
	}
	if (getcwd(tmp, PATH_MAX))
	{
		base->cur_pwd = tmp;
		ft_putstr_fd(base->cur_pwd, base->fd_out);
		ft_putchar_fd('\n', base->fd_out);
		return (1);
	}
	return (0);
}
