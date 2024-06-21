/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:47:53 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/23 10:37:24 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*build_exec_path(char *path, char *cmd)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;

	if (!cmd)
		return (NULL);
	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd);
	free(tmp);
	ret = ft_strdup_gc(tmp2, 8);
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
		if (!exec_path)
			return (NULL);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			return (exec_path);
		}
		i++;
	}
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
		return (ft_strdup_gc(input, 8));
	tmp = get_my_env("PATH", env);
	path = ft_split_gc(tmp, ':', 8);
	free(tmp);
	s_cmd = ft_split_gc(input, ' ', 8);
	ret = get_path_tab2(path, s_cmd);
	return (ret);
}

int	check_space_in_token_one(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_exec_prog(char **av, t_base *base)
{
	base->info_signal = 42;
	base->env_path = get_path_tab(av[0], base->env_old);
	if (!base->env_path)
		return (0);
	if (check_space_in_token_one(av[0]) == 1)
		return (0);
	if (base->env_path == NULL)
	{
		ft_putstr_fd("Failed to find executable\n", base->fd_out);
		free(base->env_path);
		return (0);
	}
	ft_spe_execve(av, base->env_old, base);
	dup2(1, base->fd_out);
	dup2(0, base->fd_in);
	return (1);
}
