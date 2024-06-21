/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:47:53 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/17 14:10:18 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*build_exec_path(char *path, char *cmd)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd);
	free(tmp);
	ret = ft_strdup(tmp2);
	free(tmp2);
	return (ret);
}

char	*get_path_tab2(char **path, char **s_cmd)
{
	char	*exec_path;
	int		i;

	i = 0;
	while (path && path[i])
	{
		exec_path = build_exec_path(path[i], s_cmd[0]);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free_tab(s_cmd);
			free_tab(path);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free_tab(s_cmd);
	free_tab(path);
	return (NULL);
}

char	*get_path_tab(char *input, char **env)
{
	char	*tmp;
	char	**path;
	char	**s_cmd;
	char	*ret;

	path = NULL;
	ret = NULL;
	if (access(input, F_OK | X_OK) == 0)
		return (ft_strdup(input));
	tmp = get_my_env("PATH", env);
	path = ft_split(tmp, ':');
	free(tmp);
	s_cmd = ft_split(input, ' ');
	ret = get_path_tab2(path, s_cmd);
	return (ret);
}
