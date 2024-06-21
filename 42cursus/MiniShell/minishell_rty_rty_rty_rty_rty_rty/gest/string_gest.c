/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:33:12 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/11 10:23:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_sstrndup(char *s, int n, int start, int imp)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)gc_alloc(sizeof(char) * (n + 1), imp);
	if (!dst)
		return (0);
	while (s[start] && i < n)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

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

int	skip_whitespace(char *string, int i)
{
	int	j;

	j = 0;
	while ((string[i + j] == ' ' || string[i + j] == '\b'
			|| string[i + j] == '\t'
			|| string[i + j] == '\n') && string[i + j] != 0)
		j++;
	return (j);
}

int	hm_ultra_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
