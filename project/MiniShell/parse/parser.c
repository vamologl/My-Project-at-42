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


char	*ft_strdup(const char *s)
{
	size_t	len;
	int		i;
	char	*dst;

	len = ft_strlen((char *)s);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s[i])
	{
		if (dst[i] == ' ' && s[i + 1] == '\0')
			break;
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	nb_char(char *s)
{
	int i;
	int j;

	int	count;

	i = 0;
	j = strlen(s);
	j--;
	while ((s[j] == ' ' || s[j] == '\t') && j > 0)
		j--;
	if (j < 0)
		return (-1);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	count = 0;
	while (i <= j)
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_strndup(const char *s, int n)
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
			break;
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
//	printf("|%ld|%s|\n",len, dst);
	return (dst);
}

void	get_input_tab(t_base *base)
{
	int i = -1; // to remove
	int	j;

	(void)i;
	(void)j;
	j = 0;
	base->tableau = ft_special_split(base->input);
	while (base->tableau[j])
	{
		//printf("%s\n", base->tableau[j]);
		base->tableau[j] = ft_strndup(base->tableau[j], nb_char(base->tableau[j]));
		j++;
	}
}

void	parser(t_base *base)
{
	get_input_tab(base);
	if (ft_strcmp("env", base->tableau[0]) == 0)
		print_list_env(base->env);
	else if (ft_strcmp("echo", base->tableau[0]) == 0)
		own_echo(base);
	return; 
}



	//chaque "mot" dans un maillon [x]
	//changer les variables env en votre valeur ($PATH -> path dans votre env) [?]
	// -> exec [?]