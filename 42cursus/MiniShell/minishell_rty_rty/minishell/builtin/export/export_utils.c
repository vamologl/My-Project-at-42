/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:51:40 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/13 13:09:01 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char **ft_tabdup(char **s)
{
	size_t	len;
	int		i;
	char	**dst;

	len = ft_tablen((char **)s);
	i = 0;
	dst = gc_alloc(sizeof(char **) * (len + 1), 2);
	if (!dst)
		return (0);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	correct_string_print(char *s, t_base *base)
{
	int i;
	int flag;
	
	flag = 0;
	i = 0;
	ft_putstr_fd("declare -x ", base->fd_out);
	while (s && s[i])
	{
		write(base->fd_out, &s[i], 1);
		if (s[i] == '=')
		{
			flag = 1;
			write(base->fd_out, "\"", 1);
		}
		i++;
	}
	if (flag == 1)
		write(base->fd_out, "\"", 1);
	ft_putstr_fd("\n", base->fd_out);
}

void	sorted2(int i1, t_base *base, int argc, char **argv)
{
	while (i1 < argc)
	{
		if (argv[i1][0] != '\0')
		{
			if (argv[i1][0] != '\a' && ft_strncmp(argv[i1], "_", 1) != 0)
			{
				correct_string_print(argv[i1], base);
				// ft_putstr_fd("declare -x ", base->fd_out);
				// ft_putstr_fd(argv[i1], base->fd_out);
				// ft_putstr_fd("\n", base->fd_out);
			}
		}
		i1++;
	}
}

void	sorted(int argc, char **tab, t_base *base)
{
	int		i1;
	int		i2;
	char	*tmp;
	char	**argv;

	argv = ft_tabdup(tab);
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
