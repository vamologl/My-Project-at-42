/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:26 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/23 11:06:28 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	countwords(char const *str, int count, int inword, int insidequotes)
{
	while (*str) 
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			if (!insidequotes) 
				inword = 0;
		} 
		else if (*str == '\"') 
		{
			insidequotes = !insidequotes;
			if (!insidequotes && inword == 0)
			{
				inword = 1;
				count++;
			}
		}
		else if (*str == '\'') 
		{
			insidequotes = !insidequotes;
			if (!insidequotes && inword == 0)
			{
				inword = 1;
				count++;
			}
		}
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		str++;
	}
	return (count);
}

void	get_input_tab(t_base *base)
{
	int i = -1; // to remove
	int	j;

	j = 0;
	base->tableau = ft_special_split(base->input);
	while (base->tableau[j])
	{
		base->tableau[j] = ft_strstrip(base->tableau[j]);
		j++;
	}
	while (base->tableau[++i])					//test 
		printf("|%s|\n", base->tableau[i]);		//test split output
}

void	parser(t_base *base)
{
	get_input_tab(base);

	return; 
}


	//chaque "mot" dans un maillon [x]
	//changer les variables env en votre valeur ($PATH -> path dans votre env) [?]
	// -> exec [?]