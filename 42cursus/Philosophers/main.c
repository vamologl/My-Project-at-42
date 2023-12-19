/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:03 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/18 11:34:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Philo.h"

static bool	init_struct_arg(int ac, char **av, t_arg *data)
{
	data->nb_arg = ac - 1;
	data->nb_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	data->time_philo_eat = -2;
	if (data->nb_arg == 5)
		data->time_philo_eat = ft_atoi(av[5]);
	if (data->nb_philosophers < 0 || data->time_to_die < 0 || \
		data->time_to_eat < 0 || data->time_to_sleep < 0 || \
		data->time_philo_eat == -2 || data->time_philo_eat == -1 || \
		data->time_philo_eat == 0)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_arg	*data;

	data = NULL;
	check_arg(ac, av);
	data = malloc(sizeof(t_arg));
	if (NULL == data)
		mem_error_arg(data);
	init_struct_arg(ac, av, data);
	print_struct(data); // debug only
	printf("%d\n", get_time());
	free(data); //placeholder end program
}
