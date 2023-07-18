/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:03:24 by vamologl          #+#    #+#             */
/*   Updated: 2023/07/13 09:03:26 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "now running !");
	mlx_loop(mlx);
}