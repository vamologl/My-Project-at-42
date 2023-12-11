/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:40:03 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 10:40:04 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PushSwap.h"

t_stack	*find_last(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	long			smallest;
	t_stack			*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
