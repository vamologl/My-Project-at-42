/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:18 by vamologl          #+#    #+#             */
/*   Updated: 2024/02/02 14:09:19 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp_spe(char *string, char *compared, int deb)
{
	int	i;

	i = 0;
	while (string[deb] == compared[i] && string[deb] != '\0' && compared[i] != '\0')
	{
		i++;
		deb++;
	}
	return (string[deb] - compared[i]);
}

void    ft_print_env(t_env *chain, char *name)
{
	if (NULL == chain)
		return ;
    while (chain->next)
	{
        if (ft_strcmp_spe(name, chain->name, 1) == 0)
        {
            printf("%s", ft_strdup(chain->value));
        }
		chain = chain->next;
	}
}

int	is_env(char *s, t_base *base)
{
	if (s[0] == '$')
		ft_print_env(base->env, s);
	else
		return (0);
	return (1);
}

void	own_echo(t_base *base)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (base->tableau[0] && !base->tableau[1])
	{
		printf("\n");
		return ;
	}
	else if (base->tableau[1])
	{
		if (ft_strcmp(base->tableau[1], "-n") == 0)
		{
			flag = 1;
			i++;
		}
		while (base->tableau[i])
		{
			if (is_env(base->tableau[i], base))
			{
				if (base->tableau[i + 1])
					printf(" ");
				i++;
			}
			else
			{
				printf("%s", base->tableau[i]);
				if (base->tableau[i + 1])
					printf(" ");
				i++;
			}
		}
		if (0 == flag)
			printf("\n");
	}
}
