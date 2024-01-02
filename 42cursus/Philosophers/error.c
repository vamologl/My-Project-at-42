/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:56:29 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:56:30 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	error_arg(void)
{
	printf("Error 1, use ./Philosopher [Number of Philosopher] ");
	printf("[time to die] [time to eat] [time to sleep] ");
	printf("(How many time a philosopher must eat)\n");
	exit (-1);
}

int	full_mem_exit(t_gest *gest, t_philos *philo, t_fork *forks)
{
	if (gest)
	{
		if (pthread_mutex_destroy(&gest->death_mutex))
			return (EXIT_FAILURE);
		if (pthread_mutex_destroy(&gest->philo_mutex))
			return (EXIT_FAILURE);
	}
	if (philo)
		free(philo);
	if (forks)
	{
		if (pthread_mutex_destroy(&forks->fork_mutex))
			return (EXIT_FAILURE);
		free(forks);
	}
	return (EXIT_SUCCESS);
}

int	gest_err(int code, t_gest *g, t_philos *philo, t_fork *forks)
{
	if (1 == code)
		error_arg();
	else if (2 == code)
		printf("Error 2, arg are not compatible");
	else if (3 == code)
		printf("Error 3, Mutex failed to initialise");
	else if (4 == code)
		printf("Error 4, failed to malloc the philosophers");
	else if (5 == code)
		printf("Error 5, a thread caused an error");
	full_mem_exit(g, philo, forks);
	return (EXIT_FAILURE);
}
