/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_tab_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:27:17 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:32:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_true_char(char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!tab)
		return (0);
	while (tab && tab[i])
	{
		if (tab[i] && tab[i][0] == '\0')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	**remove_null_in_tab(char **tab)
{
	int		j;
	int		i;
	char	**ret;

	if (!tab)
		return (NULL);
	ret = gc_alloc(sizeof(char **) * (count_true_char(tab) + 1), 6);
	j = 0;
	i = 0;
	while (i < count_true_char(tab))
	{
		if (tab[i][0] == '\0')
			i++;
		else if (tab[i])
		{
			ret[j] = ft_strdup_gc(tab[i], 4);
			i++;
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
