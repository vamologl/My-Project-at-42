/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:07:55 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/05 10:42:31 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**make_map(int fd)
{
	char	**ret;
	char	*tmp;
	char	*tmp2;

	tmp2 = gc_alloc(sizeof(char *) + 1, 2);
	tmp = NULL;
	tmp2[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin_gc(tmp2, tmp, 3);
		free(tmp);
	}
	ret = ft_split_gc(tmp2, '\n', 7);
	if (tmp)
		free(tmp);
	return (ret);
}

int	count_char(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**build_map(int fd)
{
	char	**ret;

	ret = make_map(fd);
	return (ret);
}
