/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:55:14 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/09 10:53:40 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_pipeline4(char ***command, t_base *base)
{
	if (is_there_redir(command[base->pipe->i]) != 0)
	{
		gest_pipe_and_redir2(base, command, base->pipe->i);
	}
	else
	{
		get_file_inpout(base, command[base->pipe->i], base->pipe->i);
		get_command(command, base->pipe->i, base);
	}
	close(base->pipe->pipefd[0]);
	close(base->pipe->pipefd[1]);
	ft_exit_alt(base, EXIT_FAILURE);
}

void	execute_pipeline3(char ***command, int nb_cmds, t_base *base)
{
	if (base->pipe->i != 0)
	{
		if (dup2(base->pipe->prev_pipe_read, base->fd_in) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(base->pipe->prev_pipe_read);
	}
	if (base->pipe->i < nb_cmds - 1)
	{
		if (dup2(base->pipe->pipefd[1], base->fd_out) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
	}
	execute_pipeline4(command, base);
}

void	execute_pipeline2(int nb_cmds, t_base *base)
{
	wait(NULL);
	if (base->pipe->i < nb_cmds - 1)
	{
		close(base->pipe->pipefd[1]);
		base->pipe->prev_pipe_read = base->pipe->pipefd[0];
	}
}

void	execute_pipeline_init(t_base *base)
{
	base->pipe->i = 0;
	base->pipe->pipefd[0] = 0;
	base->pipe->pipefd[1] = 0;
	base->pipe->prev_pipe_read = base->fd_in;
}

void	execute_pipeline(char ***command, int nb_cmds, t_base *base)
{
	g_signal = SIGUSR2;
	execute_pipeline_init(base);
	while (base->pipe->i < nb_cmds)
	{
		if (base->pipe->i < nb_cmds - 1)
		{
			if (pipe(base->pipe->pipefd) < 0)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}
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
}
