/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:59:53 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/06 13:35:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

static inline int	modif_edge(char c, char edge)
{
	if (edge == ' ')
		return (c);
	else if (c != edge)
		return (edge);
	else
		return (' ');
}

int	ft_super_countwords(const char *s)
{
	int		i;
	int		count;
	char	edge;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(s))
	{
		edge = ' ';
		while (s[i] == edge)
			i++;
		if (i >= (int)ft_strlen(s))
			break ;
		if (is_quote(s[i]))
			edge = modif_edge(s[i++], edge);
		count++;
		while (i < (int)ft_strlen(s) && s[i] != ' ')
		{
			if (is_quote(s[i]))
				edge = modif_edge(s[i], edge);
			i++;
		}
		i++;
	}
	return (count);
}

char	*ft_skip_spaces(char *s)
{
	while (*s && *s == ' ')
		s++;
	return (s);
}

int	ft_get_word_size(const char *s)
{
	int		size;
	char	quote;

	quote = 0;
	size = 0;
	while (s[size])
	{
		if (s[size] == '\"' && quote == 0)
			quote = '\"';
		else if (s[size] == '\'' && quote == 0)
			quote = '\'';
		else if (s[size] == ' ' && quote == 0)
			break ;
		else if (s[size] == quote)
			quote = 0;
		size++;
	}
	return (size);
}
