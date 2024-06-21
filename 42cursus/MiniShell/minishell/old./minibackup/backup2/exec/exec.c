/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:25:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/18 15:37:37 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		i++;
	}
	return (0);
}

void	free_exec(t_base *base)
{
	rl_clear_history();
	free(base->tableau);
	if (base->input)
		free(base->input);
	if (base->user)
		free(base->user);
	if (base->output_file)
		free(base->output_file);
	if (base->command)
		free(base->command);
	close(base->terminal_in);
	close(base->terminal_out);
}

int	ft_spe_execve2(char **av, char **tab, t_base *base)
{
	int	fd_tmp;
	int	fd_tmp2;

	fd_tmp = dup(1);
	fd_tmp2 = dup(0);
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
	base->return_value = execve(base->env_path, av, tab);
	ft_putstr_fd(av[0], base->fd_out);
	ft_putstr_fd(" : Is a directory\n", base->fd_out);
	dup2(fd_tmp2, 0);
	dup2(fd_tmp, 1);
	gc_free_all();
	exit(126);
}

int	ft_spe_execve(char **av, char **tab, t_base *base)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_spe_execve2(av, tab, base);
	else
	{
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

int	ft_exec_prog(char **av, t_base *base)
{
	base->env_path = get_path_tab(av[0], base->env_old);
	if (!base->env_path)
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
