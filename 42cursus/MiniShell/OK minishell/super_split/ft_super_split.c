/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_split2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:01:17 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 12:02:36 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_extract_word(char const *s, int size)
{
	char	*word;
	int		i;

	i = 0;
	word = gc_alloc((size + 1) * sizeof(char), 6);
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[size] = '\0';
	return (word);
}

int	ft_super_while(char *s, char **strs, int word_count)
{
	int	j;
	int	word_size;

	j = 0;
	word_size = 0;
	while (*s && j < word_count)
	{
		s = ft_skip_spaces(s);
		word_size = ft_get_word_size(s);
		if (j > 0 && *(s - 1) == '=' && word_size == 0)
			word_size++;
		strs[j] = ft_extract_word(s, word_size);
		if (!strs[j])
		{
			while (j > -1)
				free(strs[j--]);
			free(strs);
			free(s);
			return (0);
		}
		j++;
		s += word_size;
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_super_split(char *s)
{
	char	**strs;
	int		word_count;

	word_count = ft_super_countwords(s);
	strs = gc_alloc((word_count + 1) * sizeof(char *), 6);
	if (!strs)
		return (NULL);
	if (!ft_super_while(s, strs, word_count))
	{
		while (*strs)
			free(*strs++);
		free(strs);
		return (NULL);
	}
	return (strs);
}
