/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:54:35 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/29 10:28:39 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_env_old(char **env_old, char *str)
{
	int	i;

	i = 0;
	while (env_old && env_old[i])
	{
		if (env_old[i][0] == '\0')
		{
			env_old[i] = ft_strdup_gc(str, 5);
			return ;
		}
		i++;
	}
	env_old[i] = ft_strdup_gc(str, 5);
	env_old[i + 1] = NULL;
}

int	already_exist(char **env, char *string)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(string, env[i],
				ft_strclen(string, '=')) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_export2(t_base *base, int *i, char **ret)
{
	if (check_if_storable(ret[(*i)]) == 0)
	{
		ft_putstr_fd("Error export - `", base->fd_out);
		ft_putstr_fd(ret[(*i)], base->fd_out);
		ft_putstr_fd("\': a valid identifier\n", base->fd_out);
	}
	else
	{
		if (already_exist(base->env_old, ret[(*i)]) == 0)
			add_env_old(base->env_old, ret[(*i)]);
		else
			update_env_old(base, ret[(*i)]);
	}
	(*i)++;
}

int	ft_export(t_base *base, int j)
{
	char	**ret;
	int		i;

	if (base->dl_redir == 1 && base->dl_redir_check_break != 1)
	{
		g_return_code = 130;
		return (130);
	}
	i = 1;
	g_return_code = 0;
	if (!base->input)
		return (0);
	ret = base->tableau[j];
	if (ret[1] == NULL && ft_strcmp(ret[0], "export") == 0)
	{
		sorted(ft_tablen(base->env_old), base->env_old, base);
		return (1);
	}
	while (ret[i])
		ft_export2(base, &i, ret);
	return (1);
}
