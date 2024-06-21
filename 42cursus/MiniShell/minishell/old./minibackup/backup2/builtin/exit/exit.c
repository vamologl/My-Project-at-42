/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:02 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/22 11:34:11 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_long_tab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return ;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
}

/*
1 = tableau		| full tab*** var
2 = link		| list for environement
3 = tableau[x]	| tab[x][0] - tab[x][1]
4 = addsr		| add address 
5 = env			| 
6 = ft_shlvl	| for a itoa that leak 
					Schrödinger invalid free
*/

void	ft_gc_free(void)
{
	gc_free_p(1);
	gc_free_p(2);
	gc_free_p(3);
	gc_free_p(5);
	gc_free_p(6);
	gc_free_p(4);
	gc_free_p(-1);
	gc_free_p(8);
	gc_free_p(7);
}

void	free_base(t_base *base)
{
	if (base->output_file)
		free(base->output_file);
	if (base->command)
		free(base->command);
	close(base->terminal_in);
	close(base->terminal_out);
	close(base->fd_out);
	close(base->fd_in);
	rl_clear_history();
	ft_gc_free();
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_base *base, int i)
{
	int	tmp;

	tmp = 1;
	if (i == 2)
	{
		message(base);
		free_base(base);
		exit(tmp);
	}
	if (base->tablen < 2 && ft_tablen(base->tableau[i]) > 2
		&& ft_is_num(base->tableau[i][1]) == 1)
	{
		ft_putstr_fd("exit: too many arguments\n", base->fd_out);
		return ;
	}
	if (base->tablen < 2 && ft_check_char(base->tableau[i][1], base) == 2)
		tmp = 2;
	else if (ft_tablen(base->tableau[i]) == 2)
		tmp = ft_atoi(base->tableau[i][1]);
	if (base->tablen <= 1)
		message(base);
	free_base(base);
	gc_free_all();
	exit(tmp);
}
