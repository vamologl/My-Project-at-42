/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:56:46 by vamologl          #+#    #+#             */
/*   Updated: 2024/01/02 09:56:47 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	main(int argc, char **argv)
{
	t_args		a;
	t_gest		g;
	t_philos	*philos;
	t_fork		*forks;

	if (argc < 5 || argc > 6)
		return (gest_err(1, NULL, NULL, NULL));
	if (!init_arg(&a, argc, argv))
		return (gest_err(2, &g, NULL, NULL));
	if (!init_gest(&g, a))
		return (gest_err(3, &g, NULL, NULL));
	if (!init_philosopher(&g, &philos, &forks))
		return (gest_err(4, &g, philos, forks));
	if (!gest_threads(&g, &philos))
		return (gest_err(5, &g, philos, forks));
	return (full_mem_exit(&g, philos, forks));
}
