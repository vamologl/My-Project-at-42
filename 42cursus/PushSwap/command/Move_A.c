/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:25:56 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 13:25:59 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PushSwap.h"

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}
