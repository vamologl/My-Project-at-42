/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:24:07 by vamologl          #+#    #+#             */
/*   Updated: 2024/11/19 11:26:28 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*correct_place(char *s)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s && s[i] != 47)
		i++;
	i++;
	k = i;
	while (s && s[k] != '.')
	{
		j++;
		k++;
	}
	ret = ft_sstrndup(s, j, i, -1);
	return (ret);
}

char	*create_string_user(t_base *base)
{
	char	*user;
	char	*manage;
	char	*tmp;
	char	*tmp2;

	tmp2 = get_correct_path(base);
	user = get_var_env(base->env_old, "USER");
	manage = get_var_env(base->env_old, "SESSION_MANAGER");
	if (ft_strcmp(user, "\a\0") == 0 || ft_strcmp(manage, "\a\0") == 0)
		return (NULL);
	manage = correct_place(manage);
	tmp = ft_strjoin_gc(user, "@", 2);
	tmp = ft_strjoin_gc(tmp, manage, 2);
	tmp = ft_strjoin_gc(tmp, ":", 2);
	tmp = ft_strjoin_gc(tmp, tmp2, 2);
	tmp = ft_strjoin_gc(tmp, "$ ", 2);
	return (tmp);
}

void	init_user(t_base *base)
{
	char	*ret;

	ret = create_string_user(base);
	if (ret)
		base->user = ft_strjoin_gc("minishell@c0r0p0", ":~$ ", 2);
	else
		base->user = ret;
}
