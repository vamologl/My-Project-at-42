/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:10:29 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/24 11:16:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_find_flag(char *s, int i, int e, int flag)
{
	while (s[i] != '\0')
	{
		if (s[i] == 39 && flag == 0)
		{
			e = i;
			flag = 1;
		}
		else if (s[i] == 39 && flag == 1)
		{
			flag = 2;
			break ;
		}
		i++;
	}
}

void	*ft_find_quote(char *s)
{
	char	*buff;
	int		flag;
	int		i;
	int		e;
	int		indx;

	flag = 0;
	i = 0;
	e = 0;
	indx = 0;
	ft_find_flag(s, i, e, flag);
	if (flag != 2)
		return (NULL);
	buff = malloc(i - e + 1);
	e++;
	while (e < i)
	{
		buff[indx] = s[e];
		indx++;
		e++;
	}
	buff[indx] = '\0';
	return (buff);
}

int	ft_is_that_char(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

int	there_is_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	find_that_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
