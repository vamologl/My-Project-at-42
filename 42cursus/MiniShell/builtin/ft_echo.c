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

void	ft_echo(char **tab) // ne sert a rien. Merci le tableau
{
	if (tab[1] && ft_strcmp(tab[2], "-n"))
	{
		printf("%s", tab[2]);
		return ;
	}
	else
		printf("%s\n", tab[1]);
}

void	ft_echo(t_list *input) // basic
{
	if (NULL == input)
		return ;
	if (ft_strcmp(input->value, "echo") == 0)
		input = input->next;
	if (ft_strcmp(input->value, "-n") == 0)
	{
		input->next;
		while (input->next)
		{
			printf("%s ", input->value);
			input = input->next;
		}
		return ;
	}
	else
	{
		while (input->next)
		{
			printf("%s ", input->value);
			input = input->next;
		}
	}
	printf("\n");
}