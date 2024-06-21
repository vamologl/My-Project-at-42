/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:31:04 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/10 15:20:53 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_correct_path_path2(char *path, int count, int k)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (path[i] && j < 3)
	{
		if (path[i] == '/')
			j++;
		i++;
	}
	i--;
	while (k <= i)
		k++;
	k = i;
	while (path && path[k])
	{
		count++;
		k++;
	}
	ret = ft_sstrndup(path, count, i, 2);
	ret = ft_strjoin_gc("~", ret, 2);
	return (ret);
}

char	*check_wrong_string(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = gc_alloc(sizeof(char *) * ft_strlen(s), 2);
	while (s && s[i])
	{
		if (s[i + 1] && s[i] && s[i] == ' '
			&& (s[i + 1] == '|'
				|| s[i + 1] == '<' || s[i + 1] == '>'))
			i++;
		else if (i >= 1 && s[i] && s[i] == ' '
			&& s[i - 1] && (s[i - 1] == '>' || s[i - 1] == '<'))
			i++;
		else
		{
			ret[j] = s[i];
			i++;
			j++;
		}
	}
	ret[j] = '\0';
	return (ret);
}

int	home_path(char *path, t_base *base)
{
	char	*var;

	var = ft_strjoin_gc("/home/", get_var_env(base->env_old, "USER"), 2);
	if (ft_strcmp(var, path) == 0)
		return (1);
	return (0);
}

char	*get_correct_path(t_base *base)
{
	char	*path;
	char	*ret;
	int		count;
	int		k;

	k = 0;
	count = 0;
	path = get_var_env(base->env_old, "PWD");
	path = check_wrong_string(path);
	if (hm_that_char(path, '/') == 2 && home_path(path, base) == 1)
		return ("");
	else if (hm_that_char(path, '/') < 2
		|| (home_path(path, base) == 0 && hm_that_char(path, '/') == 2))
		return (path);
	else
	{
		ret = get_correct_path_path2(path, count, k);
		return (ret);
	}
}
