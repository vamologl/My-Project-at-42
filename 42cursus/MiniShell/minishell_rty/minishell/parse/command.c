/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:19:19 by thlefebv          #+#    #+#             */
/*   Updated: 2024/05/09 14:43:34 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_true_char(char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i] && tab[i][0] == '\0')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	**remove_null_in_tab(char **tab)
{
	int		count;
	int		j;
	int		i;
	char	**ret;

	if (!tab)
		return (NULL);
	count = count_true_char(tab);
	ret = gc_alloc(sizeof(char **) * (count + 1), 6);
	j = 0;
	i = 0;
	while (i < count)
	{
		if (tab[i][0] == '\0' || tab[i][0] == '\a')
			i++;
		else if (tab[i])
		{
			ret[j] = ft_strdup_gc(tab[i], 4);
			i++;
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}

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
			base->return_value = 126;
			free(tmp);
		}
	}
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
		get_pwd(base);
	else if (ft_strcmp("cd", tableau[j][0]) == 0)
		own_cd(base->input, base);
	else if (ft_strcmp("export", tableau[j][0]) == 0)
		ft_export(base, j);
	else if (ft_strcmp("unset", tableau[j][0]) == 0)
		ft_unset(base, j);
	else if (ft_strcmp("exit", tableau[j][0]) == 0)
		ft_exit_alt(base, j);
	else if (!ft_exec_prog(tableau[j], base)
		|| ft_strcmp(tableau[j][0], "..") == 0 ||
		ft_strcmp(tableau[j][0], ".") == 0)
	{
		base->return_value = 127;
		error_exec_handler(base, j, tableau);
	}
}

void	get_command(char ***tableau, int j, t_base *base)
{
	if (base->error_parse == 1 && ((base->tablen - 2) == -1
			|| (base->tablen - 2) == j))
	{
		ft_putstr_fd("Error : parsing\n", base->terminal_out);
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
