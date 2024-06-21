/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:07 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/06 15:10:25 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int	g_signal;

int	only_one_type_redir(char **tab)
{
	int	i;
	int	tmp_redir;

	i = 0;
	tmp_redir = -1;
	while (tab[i] && tmp_redir == -1)
	{
		if (ft_find_redirection(tab[i]) == 1)
			tmp_redir = 1;
		else if (ft_find_redirection(tab[i]) == 2)
			tmp_redir = 2;
		else if (ft_find_redirection(tab[i]) == 3)
			tmp_redir = 3;
		else if (ft_find_redirection(tab[i]) == 4)
			tmp_redir = 4;
		i++;
	}
	while (tab[i])
	{
		if (ft_find_redirection(tab[i]) != 0
			&& ft_find_redirection(tab[i]) != tmp_redir)
			return (0);
		i++;
	}
	return (1);
}

int	here_doc(char *eof, t_base *base)
{
	char	*buf;
	int		tmp;

	tmp = open("./Utils/.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	buf = NULL;
	if (!eof)
		return (-1);
	base->dl_redir = 1;
	g_signal = SIGUSR1;
	while (g_signal == SIGUSR1)
	{
		write(1, "> ", 2);
		buf = get_next_line(base->fd_in);
		if (!buf)
			break ;
		if (strncmp(eof, buf, strlen(eof)) == 0
			&& ft_strlen(eof) == ft_strlen(buf) - 1)
		{
			base->dl_redir_check_break = 1;
			break ;
		}
		write(tmp, buf, strlen(buf));
	}
	base->dl_redir = 1;
	return (0);
}
