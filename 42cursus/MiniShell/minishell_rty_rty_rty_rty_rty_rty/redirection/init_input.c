/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:49:03 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/11 15:18:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_exec(char **tab)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ret = gc_alloc(sizeof(char **) * (ft_tablen(tab) + 1), 2);
	if (!tab)
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_find_redirection(tab[i]) != 0)
			i += 2;
		else if (ft_strcmp(tab[i], "\a\0") == 0)
			i++;
		else
			ret[j++] = ft_strdup_gc(tab[i++], 2);
	}
	ret[j] = NULL;
	return (ret);
}

int	error_check_file_in(int tmp, int i, t_base *base, char **str)
{
	if (tmp != -2 && tmp != -1)
	{
		if (base->add_heredoc != 1)
			dup2(tmp, base->fd_in);
		return (0);
	}
	else if (tmp == -1)
	{
		perror(str[i + 1]);
		g_return_code = 1;
		base->flag_error_redir = 1;
		dup2(base->terminal_in, base->fd_in);
		return (1);
	}
	return (0);
}

void	set_input_while(char **str, t_base *base, int *tmp, int i)
{
	if (ft_find_redirection(str[i]) == 3)
	{
		if (!str[i + 1])
			base->error_parse = 1;
		else
		{
			(*tmp) = open(str[i + 1], O_RDONLY, 0644);
			base->add_heredoc = 0;
		}
	}
	else if (ft_find_redirection(str[i]) == 4)
	{
		here_doc(str[i + 1], base);
		base->add_heredoc = 1;
	}
	else if (ft_find_redirection(str[i]) == -1)
	{
		base->error_parse = 1;
		base->flag_error_redir = 2;
	}
}

int	set_input(char **str, t_base *base, int tmp)
{
	int	i;
	int	fd_tmp;

	(void)tmp;
	fd_tmp = -2;
	i = 0;
	while (str[i] && base->error_parse != 1)
	{
		set_input_while(str, base, &fd_tmp, i);
		if (error_check_file_in(fd_tmp, i, base, str) == 1)
			return (1);
		i++;
	}
	return (0);
}
