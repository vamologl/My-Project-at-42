/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:56:58 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/11 12:58:38 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

time_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned long	get_time_elapsed(t_philos *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec - philo->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->start_time.tv_usec) / 1000);
}

int	someone_died(t_philos *philo)
{
	bool	state;

	pthread_mutex_lock(&(philo->g->death_mutex));
	state = philo->g->someone_died;
	pthread_mutex_unlock(&(philo->g->death_mutex));
	return (state);
}

void	ft_usleep(int time, t_philos *philo)
{
	int	i;

	i = 0;
	while (i < time)
	{
		if (philo->g->someone_died)
			return ;
		usleep(time / 10);
		i += time / 10;
	}
}

int	get_input_value(char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
