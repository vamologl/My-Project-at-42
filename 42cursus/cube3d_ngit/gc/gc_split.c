/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:11:00 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/27 13:54:34 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

static int	ft_lword(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_substr_gc(char const *s, unsigned int start, size_t len, int imp)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	j = ft_strlen((char *)s + start);
	if (j < len)
		len = j;
	str = (char *)gc_alloc((len + 1) * sizeof(char), imp);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split_gc(char const *s, char c, int imp)
{
	int		i;
	int		j;
	int		size;
	int		word;
	char	**strs;

	i = 0;
	j = -1;
	word = ft_nbword(s, c);
	strs = (char **)gc_alloc((word + 1) * sizeof(char *), imp);
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_lword(s, c, i);
		strs[j] = ft_substr_gc(s, i, size, imp);
		if (!strs[j])
			return (NULL);
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
