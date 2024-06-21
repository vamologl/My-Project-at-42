/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input_parser2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:48:36 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/16 15:10:51 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	correct_redirection_len(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = gc_alloc(sizeof(char) * BUFFER_SZ, 8);
	while (av && av[i])
	{
		if (av[i] == '>' || av[i] == '<')
		{
			ret[j++] = ' ';
			while (av[i] == '>' || av[i] == '<')
				ret[j++] = av[i++];
			ret[j++] = ' ';
		}
		else
			ret[j++] = av[i++];
	}
	return (j);
}

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

int	while_redir_file(char *s, int *code, int *i, int *flag)
{
	while (s[(*i)] && (*i) < (int)ft_strlen(s))
	{
		if ((s[(*i)] == '>' && s[(*i) + 1] != '>')
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

char	*init_input(char *s, t_base *base)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = correct_input_for_parser(s);
	free(s);
	tmp = correct_pipe_for_parser(tmp2);
	if (check_redir_file(tmp, base) == 0)
		base->error_parse = 1;
	return (tmp);
}
