/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/23 11:06:28 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void execute_pipeline(char ***tab, t_base *base)
{
	// int pipefd[2];
	pid_t pid;
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		// if (i < nb_com - 1)
		// {
		// 	if (pipe(pipefd) == -1)
		// 	{
		// 		perror("pipefd");
		// 		return ;
		// 	}
		// }

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return ;
		}
		else if (pid == 0)
		{
			// if (i == 0)
			// 	dup2(pipefd[1], 1);
			// else if (i == nb_com - 1)
			// 	dup2(pipefd[0], 0);
			// else
			// {
			// 	dup2(pipefd[0], 0);
			// 	dup2(pipefd[1], 1);
			// }
			// close(pipefd[0]);
			// close(pipefd[1]);
			ft_exec_prog(tab[i], base);
			exit(0);
		}
		else
		{
			waitpid(pid, NULL, 0);
			// close(pipefd[0]);
			// close(pipefd[1]);
		}
		i++;
	}
}


char	*ft_strdup(const char *s)
{
	size_t	len;
	int		i;
	char	*dst;

	dst = NULL;

	len = ft_strlen((char *)s);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s[i])
	{
		if (dst[i] == ' ' && s[i + 1] == '\0')
			break ;
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


void	fd_change(t_base *base)
{
	if (base->tableau[0][1] == NULL)
	{
		base->fd_out = 1;
		return ;
	}
	else if (base->tableau[0][2] != NULL)
	{
		dprintf(base->fd_out, "Error - too many arguments\n");
		dprintf(base->ft_custom_exit, "Error - too many arguments\n");
		return ;
	}
	else

		base->fd_out = open(base->tableau[0][1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	return ;
}

void	get_file_inpout(t_base *base, char **av)
{
	if (is_there_redir(av))
	{
		if (only_one_redir(av) == 1)
		{
			if (is_there_redir(av) == 4)
				ft_double_lredir(base);
			else if(is_there_redir(av) == 1)
				ft_basic_redir(av, base);
			else if (is_there_redir(av) == 2)
				ft_double_redir(av, base);
			else if (is_there_redir(av) == 3)
				if (ft_left_redir(av, base) != 0)
					return ;
		}
		else
			multi_redir(av, base);
	}
}


char *correct_input_for_parser(char *s)
{
	char *str;
	char *tmp;
	int i = 0;
	int j = 0;

	tmp = correct_redirection(s);
	str = malloc(sizeof(char) * correct_redirection_len(s) + 1);
	while (i < correct_redirection_len(s) && tmp[i] != '\0')
	{
		if ((tmp[0] == ' ' || tmp[0] == '\t') && i == 0 && j == 0)
			i++;
		str[j] = tmp[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(tmp);
	return (str);
}

int	hm_ultra_tab(char ***tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	find_command(t_base *base, char **s)
{
	s = get_exec(s); // get exec
	if (ft_strcmp("", s[0]) == 0)
		return ;
	else if (ft_strcmp("env",s[0]) == 0)
		print_list_env(base->env, base);
	else if (ft_strcmp("echo", s[0]) == 0)
		own_echo(base);
	else if (ft_strcmp("pwd", s[0]) == 0)
		get_pwd(base);
	else if (ft_strcmp("cd", s[0]) == 0)
		own_cd(base->input, base);
	else if (ft_strcmp("export", s[0]) == 0)
		ft_export(base);
	else if (ft_strcmp("unset", s[0]) == 0)
			ft_unset(base);
	else if (ft_strcmp("exit", s[0]) == 0)
		error(0, base);
	else if (!ft_exec_prog(s, base))
	{
		ft_putstr_fd("Error - ", 1);
		ft_putstr_fd(s[0], 1);
		ft_putstr_fd(" command not found\n", 1);
		// printf("Error - command %s not found\n", base->tableau[0][0]);
	}
}

int	count_pipe(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void	free_triple_tab(char ***tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	parser(t_base *base)
{
	int i = 0;
	int j = 0;

	dup2(base->terminal_in, base->fd_in);
	dup2(base->terminal_out, base->fd_out);

	if (find_pipe(base->input) == -1)
	{
		dprintf(base->ft_custom_exit, "no pipe\n");
		if (get_input_tab(base) == 0)
			return ;
		base->tableau[0] = get_exec(base->tableau[0]); // get exec
		find_command(base, base->tableau[0]);
	}
	else
	{
		dprintf(base->ft_custom_exit, "has pipe\n");
		base->tableau = pre_build_tab(base->input, base);
		while (base->tableau[j])
		{
			while (base->tableau[j][i])
			{
				dprintf(base->ft_custom_exit, "-- tableau[%d][%d] = %s\n",j , i, base->tableau[j][i]);
				i++;
			}
			dprintf(base->ft_custom_exit, "-- tableau[%d][%d] = %s\n",j , i, base->tableau[j][i]);
			dprintf(base->ft_custom_exit, "\n");
			i = 0;
			j++;
		}
		execute_pipeline(base->tableau, base);
		return ;
	}
	ft_bzero(base->input, ft_strlen(base->input));
	// free(base->input);
	dup2(base->terminal_in, base->fd_out);
	dup2(base->terminal_out, base->fd_in);
}