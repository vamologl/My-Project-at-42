/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:41:30 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:20:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_check_file_out(int tmp, int i, t_base *base, char **str)
{
	if (tmp != -2 && tmp != -1)
	{
		dup2(tmp, base->fd_out);
		return (0);
	}
	else if (tmp == -1)
	{
		perror(str[i + 1]);
		base->flag_error_redir = 1;
		return (1);
	}
	return (2);
}

void	set_output_while(char **str, t_base *base, int *tmp, int i)
{
	if (ft_find_redirection(str[i]) == 1)
	{
		if (!str[i + 1])
			base->error_parse = 1;
		else
			(*tmp) = open(str[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	else if (ft_find_redirection(str[i]) == 2)
	{
		if (!str[i + 1])
			base->error_parse = 1;
		else
			(*tmp) = open(str[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else if (ft_find_redirection(str[i]) == -2)
	{
		base->error_parse = 1;
		base->flag_error_redir = 2;
	}
}

void	set_output(char **str, t_base *base)
{
	int	i;
	int	tmp;

	tmp = -2;
	i = 0;
	while (str[i] && base->error_parse != 1)
	{
		set_output_while(str, base, &tmp, i);
		if (error_check_file_out(tmp, i, base, str) == 1)
			break ;
		i++;
	}
}


int	ft_triple_tablen(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
