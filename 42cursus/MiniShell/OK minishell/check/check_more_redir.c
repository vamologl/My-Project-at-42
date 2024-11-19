/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_more_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:24:00 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/10 14:08:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_find_redirection(char *s)
{
	if (s)
	{
		if (ft_strcmp(s, ">") == 0)
			return (1);
		else if (ft_strcmp(s, ">>") == 0)
			return (2);
		else if (ft_strcmp(s, "<") == 0)
			return (3);
		else if (ft_strcmp(s, "<<") == 0)
			return (4);
		else if (ft_strncmp(s, "<<", 2) == 0 && ft_strlen(s) >= 3)
			return (-1);
		else if (ft_strncmp(s, ">>", 2) == 0 && ft_strlen(s) >= 3)
			return (-2);
	}
	return (0);
}
