/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:44:21 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/14 07:55:20 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
}

stack* head = NULL;

int    push(int value, int head)
{
    stack* newstack = malloc(sizeof(stack));
    if (newstack == NULL)
        return (0);
    newstack->value = value;
    newstack->next = head;
    head = newstack;

    return (1);
}

int pull(void)
{
    int    result;
    stack* tmp;

    if (head == NULL)
        return (-4);
    result = head->value;
    tmp = head;
    head = head->next;
    free(tmp);
}

int    main(int ac, char **av)
{
    int i;
    int y;

    i = 1;
    if (ac == 1)
    {
        write(1, "Error", 5);
        return (-2);
    }
    else
    {
        push(av[i][1], 0);
        i++;
        while (i < ac)
        {
            push(av[1][i]);
            i++;
        }
    }
    while ((t = pull()) != -4)
    {
        printf("t = %d\n", t);
    }
    return (0);
}

/*
void	to_store(char value)
{
	i = 0;
	int	inta;

	inta = ft_atoi(value);
	data

}

int	main(int ac, char **av)
{
	struct test_stack stack1;
	int	i;
	(void)av;
	(void)ac;
	
	i = 1;
	stack1.indx = 1;
	stack1.val = 256;

	stack1->stack = 25;

	printf("index : %d\n", stack1.indx);
	printf("valeur : %d\n", stack1.val);

	return (0);
}*/
