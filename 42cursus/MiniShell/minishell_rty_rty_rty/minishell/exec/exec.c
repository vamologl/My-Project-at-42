/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:25:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/14 14:15:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern volatile int	g_signal;

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

void	exit_exec_ve(char **av)
{
	DIR	*tmp;

	if (g_signal != 0 && ft_strcmp(av[0], "..") != 0
		&& ft_strcmp(av[0], ".") != 0
		&& ft_strncmp(av[0], "/", 1) == 0)
	{
		tmp = opendir(av[0]);
		ft_putstr_fd(av[0], 2);
		if (tmp)
			closedir(tmp);
		ft_putstr_fd(" : is a directory\n", 2);
		gc_free_all();
		close_all(0);
		exit(126);
	}
	close_all(0);
	gc_free_all();
}

int	ft_spe_execve2(char **av, char **tab, t_base *base)
{
	g_signal = SIGUSR1;
	if (dup2(base->fd_out, 1) == -1 || dup2(base->fd_in, 0) == -1)
	{
		if (dup2(base->fd_out, 1) == -1)
			perror("Error redirecting output");
		if (dup2(base->fd_in, 0) == -1)
			perror("Error redirecting input");
		exit(EXIT_FAILURE);
	}
	if (base->dl_redir == 1)
	{
		av = build_full_exec_command(av);
		if (base->dl_redir_check_break == 1)
		{
			close_all(3);
			base->return_value = execve(base->env_path, av, tab);
		}
	}
	else
	{
		close_all(3);
		base->return_value = execve(base->env_path, av, tab);
	}
	exit_exec_ve(av);
	exit(130);
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
		if (g_signal == SIGUSR1)
			base->return_value = 130;
		if (base->dl_redir_check_break == 0 && base->dl_redir == 1)
			base->return_value = 130;
		if (WIFEXITED(status))
			base->return_value = WEXITSTATUS(status);
	}
	if (base->flag_redir == 1)
		base->flag_redir = -1;
	dup2(1, base->fd_out);
	dup2(0, base->fd_in);
	return (0);
}
