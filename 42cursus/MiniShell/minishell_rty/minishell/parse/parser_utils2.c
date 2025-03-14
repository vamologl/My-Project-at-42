/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:40:41 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/26 15:27:40 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	just_whitespace(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '\t' || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strnlen(char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*spaceless_strdup(t_base *base)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = skip_whitespace(base->input, 0);
	ret = (char *)malloc(sizeof(char) * ft_strnlen(base->input, i) + 1);
	while (base->input[i])
	{
		ret[j] = base->input[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

int	only_dots(char *s, int i)
{
	int	j;

	j = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			i++;
			j++;
			if (j >= 3)
				return (-1);
		}
		else
			return (0);
	}
	return (1);
}

int	many_dots(char *s, int i)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			i++;
			j++;
			if (j >= 2)
				flag = 1;
		}
		else if (s[i] == '/' && s[i + 1] == '\0' && flag == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}
