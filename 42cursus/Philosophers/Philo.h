/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:56:51 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:56:52 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define THINK 0
# define EAT 1
# define SLEEP 2
# define DEAD 3

# define FORK_UP 1
# define FORK_DOWN 0

# define LEFT_FORK -5
# define RIGHT_FORK 5

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}					t_fork;

typedef struct s_args
{
	int				n_philo;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	int				n_loop;
}					t_args;

typedef struct s_gest
{
	t_args			a;
	bool			someone_died;
	pthread_t		t_supervisor;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	philo_mutex;
}					t_gest;

typedef struct s_philos
{
	t_gest			*g;
	unsigned char	id;
	pthread_t		t_philosopher;
	int				loop;
	time_t			t_since_meal;
	t_fork			*has_right_fork;
	t_fork			*has_left_fork;
	bool			sr_fork;
	bool			sl_fork;
	struct timeval	start_time;
}					t_philos;

/*--Function--*/
/*-error-*/
int				gest_err(int code, t_gest *g, t_philos *philo, t_fork *forks);
int				full_mem_exit(t_gest *g, t_philos *philo, t_fork *forks);
/*-initial-*/
unsigned long	get_time_elapsed(t_philos *philo);
bool			init_philosopher(t_gest *g, t_philos **philos, t_fork **forks);
bool			init_gest(t_gest *g, t_args a);
bool			init_arg(t_args *a, int argc, char **argv);
/*-state-*/
void			*state_handler(char state, t_philos *philo, t_gest *g);
/*-threads-*/
bool			gest_threads(t_gest *g, t_philos **philos);
/*-utils-*/
time_t			get_timestamp(void);
unsigned long	get_time_elapsed(t_philos *philo);
int				someone_died(t_philos *philo);
void			ft_usleep(int time, t_philos *philo);
int				get_input_value(char *str);

#endif
