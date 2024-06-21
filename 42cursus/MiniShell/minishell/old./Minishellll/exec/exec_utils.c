/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:59:10 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 14:05:00 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

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
		str_env = ft_split(env[i], '=');
		if (str_env)
		{
			if (ft_strncmp(name, str_env[0], ft_strlen(str_env[0])) == 0)
			{
				if (str_env[1] == NULL)
					continue ;
				ret = ft_strdup(str_env[1]);
				free_tab(str_env);
				return (ret);
			}
		}
		i++;
		free_tab(str_env);
	}
	return (NULL);
}
