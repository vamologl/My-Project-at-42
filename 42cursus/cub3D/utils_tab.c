/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:48:24 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/05 11:28:00 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_tab(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
		if (!s[start + i])
			break ;
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strcmp_sl(char *s, char *c)
{
	int	i;

	i = 0;
	if (ft_strlen(s) != ft_strlen(c))
		return (-2147483647);
	while (s[i] && c[i])
	{
		if (s[i] != c[i])
			return (s[i] - c[i]);
		else
			i++;
	}
	return (s[i] - c[i]);
}
