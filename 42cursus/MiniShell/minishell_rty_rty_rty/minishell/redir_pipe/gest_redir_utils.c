/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:57:59 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/20 10:41:16 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_double_redir2(t_base *base, int i, int j)
{
	if (!base->tableau[j][i + 1])
	{
		base->error_parse = 1;
		base->fd_out = 1;
		return ;
	}
	base->fd_out = open(base->tableau[j][++i],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (base->fd_out == -1)
	{
		perror(base->tableau[j][i]);
		base->flag_error_redir = 1;
		base->fd_out = 1;
		return ;
	}
	base->flag_redir = 0;
	base->flag_error_redir = 0;
}

void	ft_double_redir(char **av, t_base *base, int j)
{
	char	**tmp;
	int		i;

	(void)av;
	i = -1;
	tmp = gc_alloc(sizeof(char **) * (ft_tablen(base->tableau[j])), 2);
	while (base->tableau[j][++i] && ft_strncmp(base->tableau[j][i]
			, ">>", ft_strlen(base->tableau[j][i])) != 0)
	{
		if (!base->tableau[j][i + 1])
		{
			base->fd_out = 1;
			return ;
		}
		tmp[i] = base->tableau[j][i];
	}
	tmp[i] = NULL;
	ft_double_redir2(base, i, j);
}

void	ft_basic_redir2(t_base *base, char **tmp, int i, int j)
{
	if (base->tableau[j][i + 1] == NULL)
	{
		base->error_parse = 1;
		base->fd_out = 1;
		free(tmp);
		return ;
	}
	free(tmp);
	i++;
	base->fd_out = open(base->tableau[j][i],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (base->fd_out == -1)
	{
		perror(base->tableau[j][i]);
		base->flag_error_redir = 1;
		base->fd_out = 1;
		return ;
	}
	base->flag_redir = 0;
	base->flag_error_redir = 0;
}

void	ft_basic_redir(char **av, t_base *base, int j)
{
	char	**tmp;
	int		i;

	(void)av;
	i = 0;
	tmp = malloc(sizeof(char **) * (ft_tablen(base->tableau[j])));
	while (ft_strncmp(base->tableau[j][i], ">"
		, ft_strlen(base->tableau[j][i])) != 0 && base->tableau[j][i])
	{
		if (base->tableau[j][i + 2] == NULL)
		{
			free(tmp);
			base->fd_out = 1;
			base->error_parse = 1;
			return ;
		}
		tmp[i] = base->tableau[j][i];
		i++;
	}
	tmp[i] = NULL;
	ft_basic_redir2(base, tmp, i, j);
}
