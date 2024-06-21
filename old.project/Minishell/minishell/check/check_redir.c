/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:05:52 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:58:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	while_redir_file2(char *s, int *code, int *i)
{
	while (s[(*i)] != '|' && s[(*i)])
	{
		if (ft_isalnum(s[(*i)]) == 1 || (s[(*i)] == '\''
				&& s[(*i + 1)] == ' ') || (s[(*i)] == '\"'
				&& s[(*i + 1)] == ' '))
		{
			(*code) = 1;
			break ;
		}
		else if ((s[(*i)] == '\'' && s[(*i + 1)] == '\'')
			|| (s[(*i)] == '\"' && s[(*i + 1)] == '\"'))
		{
			(*code) = 2;
			break ;
		}
		(*i)++;
	}
}

void	while_redir_file3(char *s, int *i)
{
	if (s[(*i)] == '\'')
	{
		while (s[(*i)] && s[(*i)] != '\'')
			(*i)++;
	}
	else
	{
		while (s[(*i)] && s[(*i)] != '\"')
			(*i)++;
	}
}

int	while_redir_file(char *s, int *code, int *i, int *flag)
{
	while ((*i) <= (int)ft_strlen(s))
	{
		if ((s[(*i)] != '\'' || s[(*i)] != '\"'))
			while_redir_file3(s, i);
		else if ((s[(*i)] == '>' && s[(*i) + 1] != '>')
			|| (s[(*i)] == '<' && s[(*i) + 1] != '<'))
		{
			(*code) = 0;
			(*flag) = 1;
			(*i)++;
			while_redir_file2(s, code, i);
			if ((s[(*i)] == '|' || s[(*i)] == '\0'))
				return (0);
		}
		(*i)++;
	}
	return (1);
}

int	check_redir_file(char *s, t_base *base)
{
	int	i;
	int	code;
	int	flag;

	i = 0;
	flag = 0;
	code = 0;
	while_redir_file(s, &code, &i, &flag);
	if (flag == 1)
	{
		if (code == 2)
		{
			base->here_doc = 1;
			code = 1;
		}
		return (code);
	}
	return (1);
}

int	is_there_redir(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_find_redirection(s[i]) == 1)
			return (1);
		else if (ft_find_redirection(s[i]) == 2)
			return (2);
		else if (ft_find_redirection(s[i]) == 3)
			return (3);
		else if (ft_find_redirection(s[i]) == 4)
			return (4);
		else if (ft_find_redirection(s[i]) == -1)
			return (-1);
		else if (ft_find_redirection(s[i]) == -2)
			return (-2);
		i++;
	}
	return (0);
}
