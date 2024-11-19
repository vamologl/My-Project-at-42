/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:07 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/11 13:02:04 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern volatile int	g_return_code;

int	here_doc2(int tmp, t_base *base, char *eof)
{
	char	*buf;

	if (!eof && base->quotes_here_doc == 0)
		return (-1);
	write(2, "> ", 2);
	buf = get_next_line(base->fd_in);
	if (g_return_code == 130)
	{
		base->heredoc_error = 1;
		return (-2);
	}
	if (buf && ft_strcmp(buf, "empty") == 0)
		return (2);
	if ((!buf || base->here_doc == 1) && base->info_signal == 10)
		return (2);
	if (!eof && base->quotes_here_doc == 1)
	{
		if (ft_strncmp(buf, "\n", 1) == 0)
			return (1);
	}
	else if (strncmp(eof, buf, strlen(eof)) == 0
		&& ft_strlen(eof) == ft_strlen(buf) - 1)
		return (1);
	write(tmp, buf, strlen(buf));
	return (0);
}

int	here_doc_error(int stor, char *eof, t_base *base, int mode)
{
	(void)eof;
	(void)stor;
	if (mode == 1)
	{
		base->heredoc_error = 1;
		ft_putstr_fd("warning: here-document at ", 2);
		ft_putstr_fd("line 1 delimited by end-of-file ", 2);
		ft_putstr_fd("(wanted `", 2);
		ft_putstr_fd(eof, 2);
		ft_putstr_fd("\')\n", 2);
		return (-5);
	}
	if (mode == 2)
	{
		base->heredoc_error = 1;
		ft_putstr_fd("Error - syntax error near unexpected token `", 2);
		ft_putstr_fd("newline", 2);
		ft_putstr_fd("\'\n", 2);
		return (-6);
	}
	base->info_signal = SIGUSR1;
	base->dl_redir = 1;
	return (0);
}

int	here_doc(char *eof, t_base *base)
{
	int		tmp;
	int		res;
	int		stor;

	base->heredoc_error = 0;
	stor = dup(base->fd_in);
	dup2(base->terminal_in, base->fd_in);
	tmp = open(base->path_heredoc, O_RDWR | O_CREAT | O_TRUNC, 0644);
	g_return_code = 134;
	if (here_doc_error(stor, eof, base, 0) == -1)
		return (-1);
	while (1)
	{
		res = here_doc2(tmp, base, eof);
		if (res == 1)
			base->dl_redir_check_break = 1;
		else if (res == 2)
			here_doc_error(stor, eof, base, 1);
		else if (res == -1)
			here_doc_error(stor, eof, base, 2);
		if (res == -1 || res == 1 || res == 2 || res == -2)
			break ;
	}
	dup2(stor, base->fd_in);
	return (0);
}
