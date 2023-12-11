/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:39:56 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 10:39:58 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PushSwap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	else if (2 == ac)
		av = ft_split(av[1], ' ');
	initial_stack(&a, av + 1, 2 == ac);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			mini_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
