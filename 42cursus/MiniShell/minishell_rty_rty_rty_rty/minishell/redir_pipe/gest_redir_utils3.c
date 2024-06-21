/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:48:14 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/24 12:57:30 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_left_redir2(t_base *base, int i, int j)
{
	if (base->tableau[j][i + 1] == NULL)
	{
		base->fd_in = 0;
		return (1);
	}
	i++;
	base->fd_in = open(base->tableau[j][i], O_RDONLY, 0644);
	if (base->fd_in == -1)
	{
		perror(base->tableau[j][i]);
		base->flag_error_redir = 1;
		base->fd_in = 1;
		return (-1);
	}
	base->flag_redir = 1;
	base->flag_error_redir = 0;
	return (0);
}

int	ft_left_redir(char **av, t_base *base, int j)
{
	char	**tmp;
	int		i;

	(void)av;
	i = 0;
	tmp = gc_alloc(sizeof(char **) * (ft_tablen(base->tableau[j])), 2);
	while (ft_strncmp(base->tableau[j][i], "<",
		ft_strlen(base->tableau[j][i])) != 0 && base->tableau[j][i])
	{
		if (base->tableau[j][i + 1] == NULL)
		{
			base->fd_in = 0;
			return (1);
		}
		tmp[i] = base->tableau[j][i];
		i++;
	}
	tmp[i] = NULL;
	ft_left_redir2(base, i, j);
	base->dl_redir = 0;
	return (0);
}

void	ft_double_lredir(t_base *base, int j)
{
	int	i;
	int	tmp;
	int	tmpfd;

	tmpfd = base->fd_in;
	tmp = -2;
	i = 0;
	dup2(base->terminal_in, base->fd_in);
	while (base->tableau[j][i] != NULL)
	{
		if (ft_strcmp(base->tableau[j][i], "<<") == 0)
			tmp = here_doc(base->tableau[j][i + 1], base);
		i++;
	}
	dup2(tmpfd, base->fd_in);
	if (tmp && tmp == -1)
		base->dl_redir = -1;
}
