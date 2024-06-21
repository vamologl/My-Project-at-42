/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:48:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/21 10:48:25 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_tab(char **av)
{
	int i;
	
	i = 0;
	while (av && av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
}

int	tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}