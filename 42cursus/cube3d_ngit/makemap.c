/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:07:55 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/28 10:55:59 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**make_map(int fd)
{
	char **ret;
	char *tmp;
	char *tmp2;
	char *buf;

	tmp2 = gc_alloc(sizeof(char *) + 1, 1);
	tmp = NULL;
	tmp2[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		buf = tmp2;
		tmp2 = ft_strjoin_gc(tmp2, tmp, 1);
		free(buf);
		free(tmp);
	}
	ret = ft_split_gc(tmp2, '\n', 1);
	if (tmp)
		free(tmp);
	free(tmp2);
	return (ret);
}

/*---------------------------------------------------------*/


