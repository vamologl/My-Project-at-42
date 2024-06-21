/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:06 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/17 11:57:38 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(char *s, int n)
{
	size_t	len;
	int		i;
	char	*dst;

	len = nb_char((char *)s);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s[i] && i <= n)
	{
		if (s[i] == ' ' && s[i + 1] == '\0')
			break ;
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	free(s);
	return (dst);
}

int	is_there_char(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	get_input_tab(t_base *base, int i)
{
	int		j;
	char	*to_free;

	j = 0;
	base->tableau[i] = ft_super_split(base->input);
	base->tablen = 1;
	while (base->tableau[i][j])
	{
		to_free = base->tableau[i][j];
		base->tableau[i][j] = modif_token(base->tableau[i][j], base);
		j++;
	}
}
