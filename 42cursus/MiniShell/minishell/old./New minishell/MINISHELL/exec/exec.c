/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:25:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/01 13:35:33 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern volatile sig_atomic_t	g_signal;

int	is_there_redir(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_find_redirection(s[i]) == 1)
			return (1);
		else if (ft_find_redirection(s[i]) == 2)
			return (2);
		else if (ft_find_redirection(s[i]) == 3)
			return (3);
		else if (ft_find_redirection(s[i]) == 4)
			return (4);
		else if (ft_find_redirection(s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

char	**build_full_exec_command(char **av)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = i;
	if (av && (ft_strcmp(av[0], "cat") == 0 || ft_strcmp(av[0], "grep") == 0))
	{
		ret = gc_alloc(sizeof(char *) * (ft_tablen(av) + 2), -4);
		while (av && av[i])
		{
			ret[j] = ft_strdup_gc(av[i], -4);
			i++;
			j++;
		}
		ret[j] = ft_strjoin_gc("", "Utils/.tmp", -4);
		j++;
		ret[j] = NULL;
		return (ret);
	}
	else
		return (av);
}

int	ft_spe_execve2(char **av, char **tab, t_base *base)
{
	if (dup2(base->fd_out, 1) == -1)
	{
		perror("Error redirecting output");
		exit(EXIT_FAILURE);
	}
	if (dup2(base->fd_in, 0) == -1)
	{
		perror("Error redirecting input");
		exit(EXIT_FAILURE);
	}
	if (base->dl_redir == 1)
		av = build_full_exec_command(av);
	base->return_value = execve(base->env_path, av, tab);
	if (g_signal != 0)
		exit(130);
	ft_putstr_fd(av[0], base->fd_out);
	if (ft_strcmp(av[0], ".") == 0)
		ft_putstr_fd(" : usage: . filename [arguments]\n",
			base->fd_out);
	else if (ft_strcmp(av[0], "..") != 0)
		ft_putstr_fd(" : Is a directory\n", base->fd_out);
	gc_free_all();
	exit(126);
}

int	ft_spe_execve(char **av, char **tab, t_base *base)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_spe_execve2(av, tab, base);
	else
	{
		g_signal = SIGUSR1;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			base->return_value = WEXITSTATUS(status);
	}
	if (base->flag_redir == 1)
		base->flag_redir = -1;
	dup2(1, base->fd_out);
	dup2(0, base->fd_in);
	return (0);
}
