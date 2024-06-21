/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_AnB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:04 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 13:26:07 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PushSwap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
