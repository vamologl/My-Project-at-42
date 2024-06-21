/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:25:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 13:56:22 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_exec_prog(char **av, t_base *base)
{
	int	status;

	status = 0;
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
	ft_spe_execve(av, base->env_old, base, status);
	dup2(1, base->fd_out);
	dup2(0, base->fd_in);
	return (1);
}

void	exit_exec_ve(char **av, t_base *base)
{
	DIR	*tmp;

	if (base->info_signal != 0 && ft_strcmp(av[0], "..") != 0
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
	base->info_signal = SIGUSR1;
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
		av = build_full_exec_command(av, base);
		if (base->dl_redir_check_break == 1)
		{
			close_all(3);
			base->return_value = execve(base->env_path, av, tab);
		}
	}
	else if (base->dl_redir == 0)
	{
		close_all(3);
		base->return_value = execve(base->env_path, av, tab);
	}
	exit_exec_ve(av, base);
	exit(130);
}

int	ft_spe_execve(char **av, char **tab, t_base *base, int status)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_spe_execve2(av, tab, base);
	else
	{
		base->info_signal = SIGUSR1;
		waitpid(pid, &status, 0);
		if (g_return_code == 131)
			g_return_code = 131;
		else if ((g_return_code == 130 && (base->dl_redir_check_break == 0
					&& base->dl_redir == 1)) || g_return_code == 130)
			g_return_code = 130;
		else if (WIFEXITED(status) && g_return_code != 131)
			g_return_code = WEXITSTATUS(status);
	}
	if (base->flag_redir == 1)
		base->flag_redir = -1;
	dup2(1, base->fd_out);
	dup2(0, base->fd_in);
	return (0);
}
