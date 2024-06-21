/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:04:32 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/24 11:20:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

volatile int	g_return_code;

void	init_path(t_base *base)
{
	char	*strtmp;

	strtmp = ft_strjoin_gc("OLDPWD=", return_pwd(), 2);
	update_env_old(base, strtmp);
	strtmp = ft_strjoin_gc("PWD=", return_pwd(), 2);
	update_env_old(base, strtmp);
}

void	init_base(t_base *base, char **env)
{
	base->tableau = NULL;
	base->tableau = gc_alloc((sizeof(char ***) * 1024), 1);
	base->input = NULL;
	base->user = NULL;
	base->cur_pwd = NULL;
	base->env_old = env;
	base->output_file = NULL;
	base->command = NULL;
	base->terminal_in = dup(1);
	base->terminal_out = dup(0);
	base->fd_in = dup(1);
	base->fd_out = dup(0);
	base->env_path = NULL;
	base->flag_redir = 0;
	g_return_code = 0;
	base->return_value_flag = 0;
	base->loop = 0;
	base->tablen = 0;
	base->flag_error_redir = 0;
	base->dl_redir_check_break = 0;
	base->error_parse = 0;
	base->here_doc = 0;
}

void	gest_shlvl(t_base *base)
{
	int		tmp;
	int		i;
	char	*tmp2;

	i = 0;
	tmp2 = get_var_env(base->env_old, "SHLVL");
	tmp = ft_atoi(tmp2);
	tmp++;
	tmp2 = ft_itoa_gc(tmp, 4);
	while (base->env_old && base->env_old[i])
	{
		if (ft_strncmp(base->env_old[i], "SHLVL=", 6) == 0)
		{
			base->env_old[i] = ft_strjoin_gc("SHLVL=", tmp2, 4);
			return ;
		}
		i++;
	}
}
