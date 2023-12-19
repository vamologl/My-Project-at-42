/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:46:40 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/18 13:46:44 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

void	print_struct(t_arg *data) // debug function
{
	printf("%d\n", data->nb_philosophers);
	printf("%d\n", data->time_to_die);
	printf("%d\n", data->time_to_eat);
	printf("%d\n", data->time_to_sleep);
	if (data->nb_arg == 5)
		printf("%d\n", data->time_philo_eat);
}
