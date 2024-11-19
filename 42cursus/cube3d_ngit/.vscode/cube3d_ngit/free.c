/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:39:51 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 14:38:29 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include.h"

int	ft_gest_exit_windowless(t_cube *cube)
{
	gc_free_p(7);
	mlx_destroy_image(cube->mlx, cube->texture->img);
	mlx_destroy_image(cube->mlx, cube->texture1->img);
	mlx_destroy_image(cube->mlx, cube->texture2->img);
	mlx_destroy_image(cube->mlx, cube->texture3->img);
	if (cube->check_door == 1)
		mlx_destroy_image(cube->mlx, cube->texture4->img);
	gc_free_p(4);
	mlx_destroy_display(cube->mlx);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	exit(0);
}

int	ft_gest_exit(t_cube *cube)
{
	if (cube->loaded == 1)
		gc_free_p(7);
	mlx_destroy_image(cube->mlx, cube->texture->img);
	mlx_destroy_image(cube->mlx, cube->texture1->img);
	mlx_destroy_image(cube->mlx, cube->texture2->img);
	mlx_destroy_image(cube->mlx, cube->texture3->img);
	if (cube->check_door == 1)
		mlx_destroy_image(cube->mlx, cube->texture4->img);
	gc_free_p(4);
	mlx_destroy_window(cube->mlx, cube->win);
	mlx_destroy_display(cube->mlx);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	exit(0);
}

void	error_initmap_free(t_cube *cube)
{
	gc_free_p(7);
	gc_free_p(4);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	exit(1);
}
