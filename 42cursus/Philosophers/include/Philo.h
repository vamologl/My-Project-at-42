/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:57:42 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/13 12:57:43 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*--Macros--*/

	/*-philosopher state-*/
# define DEAD 0
# define SLEEP 1
# define EAT 2
# define THINK 3

	/*-fork-*/
# define LEFT_FORK -5
# define RIGHT_FORK 5
# define FORK_DOWN 0
# define FORK_UP 1

/*--Libs--*/
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

/*--Struc--*/

	/*-struc for fork-*/
typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}				t_fork;

	/*-just a struct that act as global function-*/
typedef struct s_arg
{
	int	nb_arg;
	int	nb_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_philo_eat;
}				t_arg;

	/*-structure for the gestion-*/
typedef struct s_gest
{
	t_arg			a;
	pthread_mutex_t	mutex_philosopher;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_print;
	bool			is_dead;
}				t_gest;

	/*-struct for all the philosopher-*/
typedef struct s_philos
{
	unsigned int	id;
	pthread_t		t_philosopher;
	struct timeval	start_time;
	int				loop;
	time_t			since_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	bool			has_left_fork;
	bool			has_right_fork;
}				t_philos;

/*--Function--*/

	/*-utils/atoi-*/
int		ft_atoi(const char *str);

	/*-error-*/
void	not_enough_arg(void);
void	not_int(void);
bool	arg_int_check(int ac, char **av);
void	mem_error_arg(void *data);

	/*-utils/time-*/
int		get_time(void);

	/*-debug file-*/
void	print_struct(t_arg *data);
void	check_arg(int ac, char **av);

#endif
