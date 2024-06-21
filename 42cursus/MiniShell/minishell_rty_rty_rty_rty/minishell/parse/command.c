/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:19:19 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:47 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern volatile int	g_return_code;

void	error_exec_handler(t_base *base, int j, char ***tableau)
{
	DIR	*tmp;

	echo_putstr_fd(base->tableau[j][0], base->terminal_out);
	if (ft_strcmp(tableau[j][0], ".") == 0)
		ft_putstr_fd(" : usage: . filename [arguments]\n", base->terminal_out);
	else if (ft_strcmp(tableau[j][0], ".") == 0)
		ft_putstr_fd(" : Is a directory\n", base->terminal_out);
	else if (ft_strncmp(tableau[j][0], "/", 1) == 0)
	{
		tmp = opendir(tableau[j][0]);
		if (!tmp)
			ft_putstr_fd(" : no such file of directory\n", base->terminal_out);
		else
		{
			ft_putstr_fd(" : is a directory\n", base->terminal_out);
			g_return_code = 126;
			free(tmp);
		}
	}
	else if (g_return_code == 130)
		return ;
	else if (ft_strcmp(tableau[j][0], ".") != 0)
		ft_putstr_fd(": command not found\n", base->terminal_out);
}

void	get_builtin(char ***tableau, int j, t_base *base)
{
	if (tableau[j] == NULL)
		return ;
	else if (ft_strcmp("env", tableau[j][0]) == 0)
		own_env(base, j);
	else if (ft_strcmp("pwd", tableau[j][0]) == 0)
		get_pwd(base, 0);
	else if (ft_strcmp("cd", tableau[j][0]) == 0)
		own_cd(j, base);
	else if (ft_strcmp("export", tableau[j][0]) == 0)
		ft_export(base, j);
	else if (ft_strcmp("unset", tableau[j][0]) == 0)
		ft_unset(base, j);
	else if (ft_strcmp("exit", tableau[j][0]) == 0)
		ft_exit_alt(base, j, 0, g_return_code);
	else if (!ft_exec_prog(tableau[j], base)
		|| ft_strcmp(tableau[j][0], "..") == 0 ||
		ft_strcmp(tableau[j][0], ".") == 0)
	{
		error_exec_handler(base, j, tableau);
		if (g_return_code != 130)
			g_return_code = 127;
	}
}

void	get_command(char ***tableau, int j, t_base *base)
{
	if ((base->error_parse == 1 && ((base->tablen - 2) == -1
				|| (base->tablen - 2) == j)) || base->flag_error_redir == 1)
	{
		if (base->flag_error_redir != 1)
		{
			if (base->here_doc == 1 || base->error_parse == 1)
				ft_putstr_fd("Error : File or directory missing\n",
					base->terminal_out);
			else
				ft_putstr_fd("Error : Parsing\n", base->terminal_out);
		}
		g_return_code = 2;
		return ;
	}
	tableau[j] = remove_null_in_tab(tableau[j]);
	if (no_command(tableau[j]) == 0 && base->error_parse != 1)
	{
		if (ft_strcmp("", tableau[j][0]) == 0)
			return ;
		else if (ft_strcmp("echo", tableau[j][0]) == 0)
			own_echo(base, j);
		else
			get_builtin(tableau, j, base);
	}
}
