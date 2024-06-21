/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:07 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/24 13:58:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern volatile int	g_return_code;

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

int	here_doc2(char *buf, int tmp, t_base *base, char *eof)
{
	write(2, "> ", 2);
	buf = get_next_line(base->fd_in);
	if (!buf || base->here_doc == 1)
	{
		if (base->info_signal == 0)
			g_return_code = 130;
		else if (base->info_signal == 10)
		{
			ft_putstr_fd("warning: here-document at ", 2);
			ft_putstr_fd("line 1 delimited by end-of-file ", 2);
			ft_putstr_fd("(wanted `", 2);
			ft_putstr_fd(eof, 2);
			ft_putstr_fd("\')\n", 2);
			return (2);
		}
	}
	if (strncmp(eof, buf, strlen(eof)) == 0
		&& ft_strlen(eof) == ft_strlen(buf) - 1)
		return (1);
	write(tmp, buf, strlen(buf));
	return (0);
}

int	here_doc(char *eof, t_base *base)
{
	char	*buf;
	int		tmp;
	int		res;

	tmp = open("./Utils/.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	g_return_code = 141;
	buf = NULL;
	if (!eof && base->here_doc != 1)
		return (-1);
	base->dl_redir = 1;
	base->info_signal = SIGUSR1;
	while (base->info_signal == SIGUSR1)
	{
		res = here_doc2(buf, tmp, base, eof);
		if (res == 1 || res == 2)
		{
			if (res == 1)
				base->dl_redir_check_break = 1;
			break ;
		}
	}
	return (0);
}
