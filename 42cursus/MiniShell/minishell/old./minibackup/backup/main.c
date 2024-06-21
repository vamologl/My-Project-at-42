/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/18 14:55:04 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	received_signal(int n)
{
	if (n == SIGTSTP || n == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (n == SIGQUIT)
		printf("\b\b  \b\b");
}

void	triple_free_tab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
	{
		j = 0;
		while (tab && tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		if (tab[i + 1] != NULL)
			i++;
	}
}

void	ft_loop(t_base *base)
{
	while (1)
	{
		base->tablen = 0;
		base->return_value_flag = 0;
		base->input = readline(base->user);
		if (base->input == NULL)
		{
			break ;
		}
		else if (is_empty(base->input) == 0)
			free(base->input);
		else if (chk_quote(base->input) != 1)
		{
			ft_putstr_fd("Error - Quotes are not closed\n", base->fd_out);
			free(base->input);
		}
		else
		{
			base->loop++;
			add_history(base->input);
			parser(base);
		}
	}
	ft_exit(base, 2);
}

int	main(int ac, char **av, char **env)
{
	t_base	*base;

	(void)ac;
	(void)av;
	signal(SIGINT, &received_signal);
	signal(SIGTSTP, &received_signal);
	signal(SIGQUIT, &received_signal);
	base = gc_alloc(sizeof(t_base), 8);
	base->pipe = gc_alloc(sizeof(t_pipeline), 8);
	init_base(base, env);
	init_user(base);
	gest_shlvl(base);
	ft_loop(base);
	rl_clear_history();
	ft_exit(base, 0);
	return (0);
}
