/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:11:48 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/06 11:11:50 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PushSwap.h"

bool	is_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->next->value < stack->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	mini_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		initial_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}
