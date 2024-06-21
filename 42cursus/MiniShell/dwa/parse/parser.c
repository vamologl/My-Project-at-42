/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 11:50:28 by vamologl         ###   ########.fr       */
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
		get_input_tab_spe(base, command[i]);
	set_input(command[i], base, -2);
	set_output(command[i], base);
	command[i] = get_exec(command[i]);
	get_command(command, i, base);
	return ;
}

void	check_empty_token_heredoc(char *s, t_base *base)
{
	int	i;

	i = 0;
	base->quotes_here_doc = 0;
	while (s[i] && s[i] != '<')
		i++;
	if (s[i] != '<' || s[i + 1] != '<')
		return ;
	while (s[i] && s[i] != '\"' && s[i] != '\'')
		i++;
	if ((s[i] == '\"' && s[i + 1] == '\"')
		|| (s[i] == '\'' && s[i + 1] == '\''))
		base->quotes_here_doc = 1;
	else
		base->quotes_here_doc = 0;
}

void	parser2(t_base *base)
{
	g_return_code = 134;
	set_output(base->tableau[0], base);
	if (set_input(base->tableau[0], base, -2) == 1)
		return ;
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
	base->loop++;
	if (base->return_value_flag == 1)
	{
		write(base->fd_out, ft_itoa(g_return_code),
			ft_strlen(ft_itoa(g_return_code)));
		write(base->fd_out, "\n", 2);
	}
	base->input = init_input(base->input, base);
	check_empty_token_heredoc(base->input, base);
	if (check_pipe(base->input) == 0)
		get_input_tab(base, 0);
	else
	{
		base->tableau = pre_build_tab(base, base->input);
		base->tableau = gest_dollar_multipipe(base, 0);
		if (check_empty_tab(base) == 1)
		{
			ft_putstr_fd("Parse error\n", base->terminal_out);
			return ;
		}
		execute_pipeline(base->tableau, hm_ultra_tab(base->tableau), base);
		return ;
	}
	parser2(base);
}
