/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:57:12 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:57:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

static void	take_fork(char which_fork, t_philos *philo)
{
	bool	*fork_state;
	t_fork	*fork;

	if (which_fork == LEFT_FORK)
	{
		fork_state = &(philo->sl_fork);
		fork = philo->has_left_fork;
	}
	else if (which_fork == RIGHT_FORK)
	{
		fork_state = &(philo->sr_fork);
		fork = philo->has_right_fork;
	}
	if (someone_died(philo))
		return ;
	if (*fork_state == FORK_DOWN)
	{
		pthread_mutex_lock(&(fork->fork_mutex));
		*fork_state = FORK_UP;
		pthread_mutex_lock(&(philo->g->print_mutex));
		if (!someone_died(philo))
			printf("%ld %d has taken a fork\n", get_time_elapsed(philo),
				philo->id);
		pthread_mutex_unlock(&(philo->g->print_mutex));
	}
}

static void	put_fork(char which_fork, t_philos *philo)
{
	bool	*fork_state;
	t_fork	*fork;

	fork_state = NULL;
	fork = NULL;
	if (which_fork == LEFT_FORK)
	{
		fork_state = &(philo->sr_fork);
		fork = philo->has_right_fork;
	}
	else if (which_fork == RIGHT_FORK)
	{
		fork_state = &(philo->sl_fork);
		fork = philo->has_left_fork;
	}
	*fork_state = FORK_DOWN;
	pthread_mutex_unlock(&(fork->fork_mutex));
}

static void	*philosopher_routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2)
		usleep(60000);
	while (!someone_died(philo) && philo->loop != philo->g->a.n_loop)
	{
		take_fork(LEFT_FORK, philo);
		if (philo->sl_fork == FORK_UP && philo->g->a.n_philo > 1)
			take_fork(RIGHT_FORK, philo);
		if (philo->sl_fork == FORK_UP && philo->sr_fork == FORK_UP)
		{
			state_handler(EAT, philo, NULL);
			put_fork(RIGHT_FORK, philo);
			put_fork(LEFT_FORK, philo);
			state_handler(SLEEP, philo, NULL);
			state_handler(THINK, philo, NULL);
		}
	}
	if (philo->sr_fork == FORK_UP)
		pthread_mutex_unlock(&(philo->has_right_fork->fork_mutex));
	if (philo->sl_fork == FORK_UP)
		pthread_mutex_unlock(&(philo->has_left_fork->fork_mutex));
	return (NULL);
}

static void	*supervisor_routine(void *arg)
{
	t_gest		*g;
	t_philos	**philos;
	int			i;

	philos = (t_philos **)arg;
	g = (*philos)->g;
	i = -1;
	while (true)
	{
		if (++i == g->a.n_philo)
			i = 0;
		pthread_mutex_lock(&(g->philo_mutex));
		if ((*philos)[i].loop == g->a.n_loop)
		{
			pthread_mutex_unlock(&(g->philo_mutex));
			return (NULL);
		}
		if (get_timestamp() - (*philos)[i].t_since_meal > g->a.tt_die / 1000)
		{
			pthread_mutex_unlock(&(g->philo_mutex));
			return (state_handler(DEAD, &((*philos)[i]), g));
		}
		pthread_mutex_unlock(&(g->philo_mutex));
	}
	return (NULL);
}

bool	gest_threads(t_gest *g, t_philos **philos)
{
	int	i;

	i = -1;
	while (++i < g->a.n_philo)
	{
		if (pthread_create(&((*philos)[i].t_philosopher), NULL,
			philosopher_routine, &((*philos)[i])))
			return (false);
	}
	if (pthread_create(&(g->t_supervisor), NULL, supervisor_routine, philos))
		return (false);
	while (i--)
	{
		if (pthread_join((*philos)[i].t_philosopher, NULL))
			return (false);
	}
	if (pthread_join(g->t_supervisor, NULL))
		return (false);
	return (true);
}
