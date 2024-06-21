/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:59:10 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/09 14:43:26 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	*get_my_env(char *name, char **env)
{
	int		i;
	char	*ret;
	char	**str_env;

	i = 0;
	ret = NULL;
	str_env = NULL;
	while (env[i])
	{
		str_env = ft_split_gc(env[i], '=', 8);
		if (str_env)
		{
			if (ft_strncmp(name, str_env[0], ft_strlen(str_env[0])) == 0)
			{
				if (str_env[1] == NULL)
					continue ;
				ret = ft_strdup(str_env[1]);
				return (ret);
			}
		}
		i++;
	}
	return (NULL);
}

int	ft_check_white_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}
