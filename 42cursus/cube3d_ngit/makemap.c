/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:07:55 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/21 14:08:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**make_map(int fd)
{
	char **ret;
	char *tmp;
	char *tmp2;
	char *buf;

	tmp2 = malloc(sizeof(char *) + 1);
	tmp = NULL;
	tmp2[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		buf = tmp2;
		tmp2 = ft_strjoin(tmp2, tmp);
		free(buf);
		free(tmp);
	}
	ret = ft_split(tmp2, '\n');
	if (tmp)
		free(tmp);
	free(tmp2);
	// int y;
	// int x;
	// y = 0;
	// x = 0;
	// while (y < tablen(ret)) // get pos player
	// {
	// 	x = 0;
	// 	while (x <= (int)ft_strlen(ret[y]))
	// 	{
	// 		printf("%c", ret[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	return (ret);
}