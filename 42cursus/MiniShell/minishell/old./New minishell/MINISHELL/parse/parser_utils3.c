/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:06 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/29 15:27:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(char *s, int n)
{
	size_t	len;
	int		i;
	char	*dst;

	len = nb_char((char *)s);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s[i] && i <= n)
	{
		if (s[i] == ' ' && s[i + 1] == '\0')
			break ;
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	free(s);
	return (dst);
}

int	is_there_char(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	get_input_tab(t_base *base, int i)
{
	int		j;
	char	*to_free;

	j = 0;
	base->tableau[i] = ft_super_split(base->input);
	base->tablen = 1;
	while (base->tableau[i][j])
	{
		to_free = base->tableau[i][j];
		base->tableau[i][j] = modif_token(base->tableau[i][j], base);
		j++;
	}
}

int	check_illegal_redir(char **av, t_base *base)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_find_redirection(av[i]) == -1)
		{
			ft_putstr_fd("Error : syntax error near unexpected token `<'\n",
				base->fd_out);
			return (1);
		}
		if (ft_find_redirection(av[i]) == -2)
		{
			ft_putstr_fd("Error : syntax error near unexpected token `>'\n",
				base->fd_out);
			return (1);
		}
		i++;
	}
	return (0);
}
