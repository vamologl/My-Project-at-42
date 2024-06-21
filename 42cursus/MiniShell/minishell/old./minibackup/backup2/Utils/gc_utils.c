/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <thlefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:07:59 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 10:14:19 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup_gc(const char *s, int imp)
{
	size_t	len;
	int		i;
	char	*dst;

	len = ft_strlen((char *)s);
	i = 0;
	dst = (char *)gc_alloc(sizeof(char) * (len + 1), imp);
	if (!dst)
		return (0);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup_gc(char *s, int n, int imp)
{
	size_t	len;
	int		i;
	char	*dst;

	len = nb_char((char *)s);
	i = 0;
	dst = gc_alloc(sizeof(char) * (len + 1), imp);
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
	return (dst);
}

char	*ft_strjoin_gc(char const *s1, char const *s2, int imp)
{
	char	*str;
	int		i;

	str = gc_alloc(sizeof(char *) * (ft_strlen((char *)s1) + \
		ft_strlen((char *)s2) + 1), imp);
	i = 0;
	if (str != NULL)
	{
		while (*s1 != '\0')
		{
			str[i] = *s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			str[i] = *s2;
			i++;
			s2++;
		}
		str[i] = '\0';
	}
	return (str);
}
