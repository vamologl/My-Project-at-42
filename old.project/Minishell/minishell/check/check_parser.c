/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:21:14 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 11:18:26 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	last_char_pipe(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = ft_strlen(s);
	i--;
	while (i >= 0 && s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		i--;
	if (i >= 0 && s && s[i] && s[i] == '|')
		return (1);
	return (0);
}

int	check_alone_redir(char *s)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!s)
		return (1);
	while (s && i <= (int)ft_strlen(s) && s[i])
	{
		if (s && s[i] && (s[i] == '>' || s[i] == '<'))
		{
			i++;
			while (s[i] && (s[i] == '>' || s[i] == '<'
					|| s[i] == ' ' || s[i] == '\t'))
				i++;
			if (s[i] == '|' || s[i] == '\0')
				flag++;
		}
		i++;
	}
	if (flag != 0)
		return (1);
	return (0);
}

int	check_parser(char *s, t_base *base)
{
	int	ret;

	ret = 0;
	if (ft_strlen(s) == 0)
		return (1);
	if (last_char_pipe(s) == 1)
	{
		g_return_code = 2;
		ret = 1;
		ft_putstr_fd("Error - no command after \'|\'\n", base->terminal_out);
	}
	else if (chk_quote(s) != 1)
	{
		g_return_code = 127;
		ret = 1;
		ft_putstr_fd("Error - Quotes are not closed\n", base->terminal_out);
	}
	else if (check_alone_redir(s) == 1)
	{
		g_return_code = 2;
		ret = 1;
		ft_putstr_fd("Error - redir has no EOF\n", base->terminal_out);
	}
	return (ret);
}
