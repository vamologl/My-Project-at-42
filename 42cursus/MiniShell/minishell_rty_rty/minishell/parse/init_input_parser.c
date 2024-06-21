/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:48:31 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/09 14:37:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*correct_pipe(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * BUFFER_SZ);
	while (av[i])
	{
		if (av[i] == '|')
		{
			ret[j++] = ' ';
			while (av[i] == '|' || av[i] == '|')
				ret[j++] = av[i++];
			ret[j++] = ' ';
		}
		else
			ret[j++] = av[i++];
	}
	ret[j] = '\0';
	return (ret);
}

int	correct_pipe_len(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = gc_alloc(sizeof(char) * BUFFER_SZ, 2);
	while (av[i])
	{
		if (av[i] == '|')
		{
			ret[j++] = ' ';
			while (av[i] == '|')
				ret[j++] = av[i++];
			ret[j++] = ' ';
		}
		else
			ret[j++] = av[i++];
	}
	ret[j] = '\0';
	return (j);
}

char	*correct_pipe_for_parser(char *s)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = correct_pipe(s);
	str = gc_alloc(sizeof(char) * correct_pipe_len(s) + 1, 9);
	while (i < correct_pipe_len(s) && tmp[i] != '\0')
	{
		if ((tmp[0] == ' ' || tmp[0] == '\t') && i == 0 && j == 0)
			i++;
		else
		{
			str[j] = tmp[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	free(tmp);
	return (str);
}

char	*correct_redirection(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = gc_alloc(sizeof(char) * BUFFER_SZ, 8);
	while (av[i])
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
	return (ret);
}

char	*correct_input_for_parser(char *s)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = correct_redirection(s);
	str = gc_alloc(sizeof(char) * correct_redirection_len(s) + 1, 7);
	while (i < correct_redirection_len(s) && tmp[i] != '\0')
	{
		if ((tmp[0] == ' ' || tmp[0] == '\t') && i == 0 && j == 0)
			i++;
		else
		{
			str[j] = tmp[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
