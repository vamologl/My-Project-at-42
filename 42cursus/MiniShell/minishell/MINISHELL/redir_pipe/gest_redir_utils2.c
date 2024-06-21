/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:41:30 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/29 14:34:34 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_output(char **str, t_base *base)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_find_redirection(str[i]) == 1)
		{
			tmp = open(str[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(tmp, base->fd_out);
			j++;
		}
		else if (ft_find_redirection(str[i]) == 2)
		{
			tmp = open(str[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			dup2(tmp, base->fd_out);
			j++;
		}
		i++;
	}
}

int	only_one_redir(char **s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_find_redirection(s[i]) != 0)
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}
