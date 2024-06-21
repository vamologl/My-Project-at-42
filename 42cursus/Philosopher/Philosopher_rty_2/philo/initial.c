/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:56:35 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:56:37 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

bool	init_philosopher(t_gest *g, t_philos **philos, t_fork **forks)
{
	t_philos	*philo;
	int			i;

	*philos = (t_philos *)malloc(sizeof(t_philos) * g->a.n_philo);
	*forks = (t_fork *)malloc(sizeof(t_fork) * g->a.n_philo);
	if (!philos || !forks)
		return (false);
	i = -1;
	while (++i < g->a.n_philo)
	{
		philo = &(*philos)[i];
		philo->g = g;
		philo->id = i + 1;
		philo->t_since_meal = get_timestamp();
		philo->loop = 0;
		philo->has_right_fork = &((*forks)[i]);
		philo->has_left_fork = &((*forks)[i + 1]);
		if (philo->id == g->a.n_philo)
			philo->has_left_fork = &((*forks)[0]);
		philo->sr_fork = FORK_DOWN;
		philo->sl_fork = FORK_DOWN;
		pthread_mutex_init(&(philo->has_left_fork->fork_mutex), NULL);
		gettimeofday(&(philo->start_time), NULL);
	}
	return (true);
}

bool	init_gest(t_gest *g, t_args a)
{
	g->a = a;
	g->someone_died = false;
	if (pthread_mutex_init(&(g->philo_mutex), NULL))
		return (false);
	if (pthread_mutex_init(&(g->death_mutex), NULL))
		return (false);
	if (pthread_mutex_init(&(g->print_mutex), NULL))
		return (false);
	return (true);
}

bool	init_arg(t_args *a, int argc, char **argv)
{
	a->n_philo = get_input_value(argv[1]);
	a->tt_die = get_input_value(argv[2]) * 1000;
	a->tt_eat = get_input_value(argv[3]) * 1000;
	a->tt_sleep = get_input_value(argv[4]) * 1000;
	a->n_loop = -2;
	if (argc == 6)
		a->n_loop = get_input_value(argv[5]);
	if (a->n_philo < 0 || a->tt_die < 0 || a->tt_eat < 0
		|| a->tt_sleep < 0 || a->n_loop < -2 || a->n_loop == -1
		|| a->n_loop == 0)
		return (false);
	return (true);
}
