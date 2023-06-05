/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:53:38 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/11 15:09:36 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int   main(void)
{
	char	*l;
	int	fd;

	fd = open("Lorem.txt", O_RDONLY);
	l = (char *)malloc(sizeof(char) + 1);
	while (fd)
	{
		l = get_next_line(fd);
		printf("%s\n", l);
	}
	return (0);
}
