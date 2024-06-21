/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input_parser2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:48:36 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/19 11:24:35 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	correct_redirection_len(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = gc_alloc(sizeof(char) * BUFFER_SZ, 8);
	while (av && av[i])
	{
		if (av[i] == '>' || av[i] == '<')
		{
			ret[j++] = ' ';
			while (av[i] == '>' || av[i] == '<')
				ret[j++] = av[i++];
			ret[j++] = ' ';
		}
		else
			ret[j++] = av[i++];
	}
	return (j);
}

char	*init_input(char *s)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = correct_input_for_parser(s);
	free(s);
	tmp = correct_pipe_for_parser(tmp2);
	return (tmp);
}
