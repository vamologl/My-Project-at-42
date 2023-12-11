/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:56:42 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 13:56:43 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PushSwap.h"

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}
