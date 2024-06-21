/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:51:40 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/18 10:26:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sorted2(int i1, t_base *base, int argc, char **argv)
{
	while (i1 < argc)
	{
		if (argv[i1][0] != '\0')
		{
			if (argv[i1][0] != '\a')
			{
				ft_putstr_fd("declare -x ", base->fd_out);
				ft_putstr_fd(argv[i1], base->fd_out);
				ft_putstr_fd("\n", base->fd_out);
			}
		}
		i1++;
	}
}

void	sorted(int argc, char **argv, t_base *base)
{
	int		i1;
	int		i2;
	char	*tmp;

	i2 = argc;
	i1 = 1;
	while (++i1 <= argc)
	{
		i2 = 1;
		while (++i2 <= argc - 1)
		{
			if (ft_strcmp(argv[i2], argv[i2 - 1]) < 0)
			{
				tmp = argv[i2];
				argv[i2] = argv[i2 - 1];
				argv[i2 - 1] = tmp;
			}
		}
	}
	i1 = 0;
	sorted2(i1, base, argc, argv);
}
