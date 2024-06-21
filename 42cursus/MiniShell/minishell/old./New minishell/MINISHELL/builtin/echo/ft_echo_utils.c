/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:19:40 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/30 15:29:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	echo_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s && s[i])
		{
			if (s && s[i] == ' ' && (s[i - 1] == '|'
					|| s[i - 1] == '<' || s[i - 1] == '>'))
				i++;
			else if (s && s[i] == ' ' && (s[i + 1] == '|'
					|| s[i + 1] == '<' || s[i + 1] == '>'))
				i++;
			else
			{
				write(fd, &s[i], 1);
				i++;
			}
		}
	}
}

int	is_env(char *s, t_base *base, int i)
{
	int	srt;
	int	end;

	srt = i;
	while (s[i])
	{
		i++;
		if ((s[i + 1] == ' ' || s[i + 1] == '\'' || s[i + 1] == '\"'))
			break ;
		else if (!ft_isalnum(s[i + 1]))
			break ;
	}
	end = i;
	printf("%s", get_var_env(base->env_old, s));
	return (i - srt + 1);
}

void	write_echo(t_base *base, int k)
{
	if (base->tableau[k][0] && !base->tableau[k][1])
	{
		ft_putchar_fd('\n', base->fd_out);
		return ;
	}
}
