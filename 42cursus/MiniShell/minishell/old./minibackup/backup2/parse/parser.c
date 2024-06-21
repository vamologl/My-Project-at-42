/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/22 14:41:49 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_input_tab_spe(t_base *base, char **command)
{
	int	j;

	j = 0;
	command = ft_super_split(base->input);
	while (command[j])
	{
		base->tableau[0][j] = ft_strndup(command[j], nb_char(command[j]));
		j++;
	}
}

void	gest_pipe_and_redir2(t_base *base, char ***command, int i)
{
	base->input = correct_input_for_parser(base->input);
	if (find_pipe(base->input) == -1)
	{
		get_input_tab_spe(base, command[i]);
	}
	get_file_inpout(base, command[i], i);
	command[i] = get_exec(command[i]);
	get_command(command, i, base);
	return ;
}

void	get_file_inpout(t_base *base, char **av, int i)
{
	if (is_there_redir(av))
	{
		if (only_one_redir(av) == 1)
		{
			if (is_there_redir(av) == 4)
				ft_double_lredir(base, i);
			else if (is_there_redir(av) == 1)
				ft_basic_redir(av, base, i);
			else if (is_there_redir(av) == 2)
				ft_double_redir(av, base, i);
			else if (is_there_redir(av) == 3)
				if (ft_left_redir(av, base, i) != 0)
					return ;
		}
		else
			multi_redir(av, base, i);
	}
}

void	parser2(t_base *base)
{
	get_file_inpout(base, base->tableau[0], 0);
	if (base->flag_error_redir != 1)
	{
		base->tableau[0] = get_exec(base->tableau[0]);
		get_command(base->tableau, 0, base);
	}
	base->flag_error_redir = 0;
	dup2(base->terminal_in, base->fd_out);
	dup2(base->terminal_out, base->fd_in);
}

void	parser(t_base *base)
{
	if (base->return_value_flag == 1)
	{
		write(base->fd_out, ft_itoa(base->return_value),
			ft_strlen(ft_itoa(base->return_value)));
		write(base->fd_out, "\n", 2);
	}
	dup2(base->terminal_in, base->fd_in);
	dup2(base->terminal_out, base->fd_out);
	base->input = init_input(base->input);
	if (find_pipe(base->input) == -1)
		get_input_tab(base, 0);
	else
	{
		base->tableau = pre_build_tab(base, base->input);
		gest_dollar_multipipe(base);
		execute_pipeline(base->tableau, hm_ultra_tab(base->tableau), base);
		return ;
	}
	parser2(base);
}
