/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:55:14 by thlefebv          #+#    #+#             */
/*   Updated: 2024/06/07 11:19:14 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_pipeline4(char ***command, t_base *base)
{
	if (is_there_redir(command[base->pipe->i]) != 0)
		gest_pipe_and_redir2(base, command, base->pipe->i);
	else
	{
		set_output(command[base->pipe->i], base);
		set_input(command[base->pipe->i], base, -2);
		get_command(command, base->pipe->i, base);
	}
	close(base->pipe->pipefd[0]);
	close(base->pipe->pipefd[1]);
	close(base->pipe->prev_pipe_read);
	close_all(0);
	ft_exit_alt(base, base->pipe->i, 1, g_return_code);
}

void	execute_pipeline3(char ***command, int nb_cmds, t_base *base)
{
	if (base->pipe->i != 0)
	{
		dup2(base->pipe->prev_pipe_read, base->fd_in);
		if (base->fd_in == -1)
		{
			perror("dup2");
			close_all(0);
			exit(EXIT_FAILURE);
		}
		close(base->pipe->prev_pipe_read);
	}
	if (base->pipe->i < nb_cmds - 1)
	{
		dup2(base->pipe->pipefd[1], base->fd_out);
		if (base->fd_out == -1)
		{
			perror("dup2");
			close_all(0);
			exit(EXIT_FAILURE);
		}
	}
	execute_pipeline4(command, base);
}

void	execute_pipeline2(int nb_cmds, t_base *base)
{
	int	status;

	status = 1;
	waitpid(base->pipe->pid, &status, 0);
	if ((ft_strcmp(base->tableau[base->pipe->i][0], "cat") == 0
		|| ft_strcmp(base->tableau[base->pipe->i][0], "grep") == 0)
			&& base->prev_ret_code == 130)
		g_return_code = 130;
	else if (WIFEXITED(status))
		g_return_code = WEXITSTATUS(status);
	if (base->pipe->i < nb_cmds - 1)
	{
		close(base->pipe->pipefd[1]);
		base->pipe->prev_pipe_read = base->pipe->pipefd[0];
	}
}

void	execute_pipeline_init(t_base *base, int mode)
{
	if (mode == 1)
	{
		base->info_signal = SIGUSR2;
		base->pipe->i = 0;
		base->pipe->pipefd[0] = 0;
		base->pipe->pipefd[1] = 0;
		base->pipe->prev_pipe_read = base->fd_in;
	}
	else if (mode == 2)
	{
		if (pipe(base->pipe->pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
}

void	execute_pipeline(char ***command, int nb_cmds, t_base *base)
{
	g_return_code = 134;
	execute_pipeline_init(base, 1);
	while (base->pipe->i < nb_cmds)
	{
		base->prev_ret_code = g_return_code;
		g_return_code = 132;
		if (base->pipe->i < nb_cmds - 1)
			execute_pipeline_init(base, 2);
		base->pipe->pid = fork();
		if (base->pipe->pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (base->pipe->pid == 0)
			execute_pipeline3(command, nb_cmds, base);
		else
			execute_pipeline2(nb_cmds, base);
		base->pipe->i++;
	}
	if (g_return_code == 130)
		printf("\n");
	close(base->pipe->pipefd[0]);
	close(base->pipe->pipefd[1]);
}
