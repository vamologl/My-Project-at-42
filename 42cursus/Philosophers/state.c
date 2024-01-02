/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:57:07 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:57:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

static void	*eat_state(t_philos *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is eating\n", get_time_elapsed(philo), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	pthread_mutex_lock(&(philo->g->philo_mutex));
	philo->t_since_meal = get_timestamp();
	pthread_mutex_unlock(&(philo->g->philo_mutex));
	ft_usleep(philo->g->a.tt_eat, philo);
	pthread_mutex_lock(&(philo->g->philo_mutex));
	philo->loop++;
	pthread_mutex_unlock(&(philo->g->philo_mutex));
	return (NULL);
}

static void	*sleep_state(t_philos *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is sleeping\n", get_time_elapsed(philo), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	ft_usleep(philo->g->a.tt_sleep, philo);
	return (NULL);
}

static void	*think_state(t_philos *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is thinking\n", get_time_elapsed(philo), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	return (NULL);
}

static void	*dead_state(t_philos *philo, t_gest *g)
{
	pthread_mutex_lock(&(g->death_mutex));
	g->someone_died = true;
	pthread_mutex_unlock(&(g->death_mutex));
	pthread_mutex_lock(&((*philo).g->print_mutex));
	printf("%ld %d died\n", get_time_elapsed(philo), (*philo).id);
	pthread_mutex_unlock(&((*philo).g->print_mutex));
	return (NULL);
}

void	*state_handler(char state, t_philos *philo, t_gest *g)
{
	if (state == EAT)
		return (eat_state(philo));
	else if (state == SLEEP)
		return (sleep_state(philo));
	else if (state == THINK)
		return (think_state(philo));
	else if (state == DEAD)
		return (dead_state(philo, g));
	return (NULL);
}
