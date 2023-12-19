/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:18 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/18 11:34:20 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Philo.h"

void	not_enough_arg(void)
{
	printf("Error - ");
	printf("./philosopher [number_of_philosopher] [time_to_die] ");
	printf("[time_to_eat] [time_to_sleep] ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	exit(-1);
}

void	not_int(void)
{
	printf("Error - arg are not supported int\n");
	exit(-2);
}

void	mem_error_arg(void *data)
{
	free(data);
	printf("ERROR - memory alloc failed");
	exit(-3);
}

bool	arg_int_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (false);
			else
				j++;
		}
		if (0 > atoi(av[i]))
			return (false);
		i++;
	}
	return (true);
}

void	check_arg(int ac, char **av)
{
	if (!arg_int_check(ac, av)) /*-error check arg for int-*/
		not_int();
	if (!(6 == ac || 5 == ac)) /*-error check if there are 5 or 6 arg-*/
		not_enough_arg();
}
