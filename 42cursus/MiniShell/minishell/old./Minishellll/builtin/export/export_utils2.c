/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:53:43 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 14:35:44 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*correct_env_var(char *env)
{
	char	*ret;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	if (!env)
		return (NULL);
	if (is_there_char(env, '=') != 1)
		return (NULL);
	while (env && env[i] != '=')
		i++;
	i++;
	j = i;
	while (env && env[j])
	{
		j++;
		count++;
	}
	ret = ft_sstrndup(env, count, i, -1);
	return (ret);
}

void	update_env_old(t_base *base, char *new_value)
{
	remove_old_env(base, new_value);
	add_env_old(base->env_old, new_value);
}

char	*get_var_env(char **env, char *name)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	if (NULL == env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(name, env[i], ft_strclen(name, '=')) == 0)
		{
			s = correct_env_var(env[i]);
			return (s);
		}
		i++;
	}
	return ("\a\0");
}
