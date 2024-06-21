/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:52:04 by vamologl          #+#    #+#             */
/*   Updated: 2024/05/09 14:17:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	while_redir_file(char *s, int *code, int *i, int *flag)
{
	while (s[(*i)] && (*i) < (int)ft_strlen(s))
	{
		if ((s[(*i)] == '>' && s[(*i) + 1] != '>')
			|| (s[(*i)] == '<' && s[(*i) + 1] != '<'))
		{
			(*code) = 0;
			(*flag) = 1;
			(*i)++;
			while (s[(*i)] != '|' && s[(*i)])
			{
				if (ft_isalnum(s[(*i)]) == 1)
				{
					(*code) = 1;
					break ;
				}
				(*i)++;
			}
			if ((s[(*i)] == '|' || s[(*i)] == '\0'))
				return (0);
		}
		(*i)++;
	}
	return (1);
}

int	check_redir_file(char *s)
{
	int	i;
	int	code;
	int	flag;

	i = 0;
	flag = 0;
	code = 0;
	while_redir_file(s, &code, &i, &flag);
	if (flag == 1)
		return (code);
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", check_redir_file(av[1]));
	return (1);
}
