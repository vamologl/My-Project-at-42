/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:48:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/28 13:31:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "include.h"
#include <math.h>

int	check_direction_player(char c, t_cube *cube)
{
	if (c == 'N' || c == 'S')
	{
		cube->player->dirX = -1;
		cube->player->dirY = 0;
		cube->player->planeX = 0.0;
		cube->player->planeY = 1;
		if (c == 'S')
		{
			cube->player->dirX *= -1;
			cube->player->planeY *= -1;
		}
	}
	else if (c == 'E' || c == 'W')
	{
		cube->player->dirX = 0;
		cube->player->dirY = 1;
		cube->player->planeX = 1;
		cube->player->planeY = -0.0;
		if (c == 'W')
		{
			cube->player->dirY *= -1;
			cube->player->planeX = -1;
		}
	}
	else
		return (ERROR);
	return(VALID);
}

int	get_player_pos(t_cube *cube)
{
	int	x;
	int	y;
	bool flag;

	flag = false;
	y = 9;
	while (y < tablen(cube->worldMap)) // get pos player
	{
		x = 0;
		while (cube->worldMap[y][x] && x < (int)ft_strlen(cube->worldMap[y]))
		{
			if (cube->worldMap[y][x] == 'N' || cube->worldMap[y][x] == 'S'
				|| cube->worldMap[y][x] == 'E' || cube->worldMap[y][x] == 'W')
			{
				if (flag == false)
				{
					check_direction_player(cube->worldMap[y][x], cube);
					cube->player->posX = y + 0.5;
					cube->player->posY = x + 0.5;
					flag = true;
				}
				else if (flag == true)
					return (ERROR);
			}
			x++;
		}
		y++;
	}
	if (!flag)
		return (ERROR); // No player
	return (VALID);
}

int	check_textures(t_cube *cube)
{
	char *tmp;

	tmp = ft_sstrndup(cube->worldMap[0], ft_strlen(cube->worldMap[0]), 3, 1); //
	cube->fd_no_tex = open(tmp, O_RDONLY);
	if (cube->fd_no_tex == -1)
	{
		dprintf(2, "test - error fd NO\n");
		return (ERROR);
	}
	tmp = ft_sstrndup(cube->worldMap[1], ft_strlen(cube->worldMap[1]), 3, 1); //
	cube->fd_so_tex = open(tmp, O_RDONLY);
	if (cube->fd_so_tex == -1)
	{
		dprintf(2, "test - error fd SO\n");
		return (ERROR);
	}
	tmp = ft_sstrndup(cube->worldMap[2], ft_strlen(cube->worldMap[2]), 3, 1); //
	cube->fd_we_tex = open(tmp, O_RDONLY);
	if (cube->fd_we_tex == -1)
	{
		dprintf(2, "test - error fd WE\n");
		return (ERROR);
	}
	tmp = ft_sstrndup(cube->worldMap[3], ft_strlen(cube->worldMap[3]), 3, 1); //
	cube->fd_ea_tex = open(tmp, O_RDONLY);
	if (cube->fd_ea_tex == -1)
	{
		dprintf(2, "test - error fd EA\n");
		return (ERROR);
	}
	return (VALID);
}

int	init_map(char *s, t_cube *cube)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (check_ext(s, (int)ft_strlen(s)) != 0)
		return (ERROR);
	if (fd == -1)
		return (ERROR); // error file
	cube->worldMap = make_map(fd);
	if (!cube->worldMap)
		return (2);
	if (get_player_pos(cube) != 0)
	{
		printf("test error - no player\n");
		return (ERROR);
	}
	if (check_symbols(cube) != 0)
		return (ERROR);
	if (checkmap(cube) != 0)
		return (ERROR);
	if (check_textures(cube) != 0)
		return (ERROR);
	printf("test - all good to go\n");

	printf("test - F - %s\n", cube->worldMap[4]);
	printf("test - C - %s\n", cube->worldMap[5]);
	
	cube->color_f = get_color(cube->worldMap[4]);
	cube->color_c = get_color(cube->worldMap[5]);
	// cube->color_c = get_color(cube->worldMap[6]);

	return (VALID);
}

int	main(int ac, char **av)
{
	t_cube *cube;
	
	cube = gc_alloc(sizeof(t_cube), 1);
	cube->player = gc_alloc(sizeof(t_player), 1);
	if (ac != 2) // check arg map
		return (1);
	if (init_map(av[1], cube) != 0) // initialize map
	{
		free(cube->player);
		free(cube);
		return (2);
	}

	cube->player->forward = 0;
	cube->player->side = 0;
	cube->player->rot = 0;
	cube->player->moveSpeed = 0.01;
	cube->player->rotSpeed = 0.01;
	
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, screenWidth, screenHeight, "cube3d | semi broken");
	draw_loop(cube);

	mlx_loop_hook(cube->mlx, draw_loop, cube);
	mlx_hook(cube->win, 17, 1L << 17, gest_key_press, cube);
	mlx_hook(cube->win, 3, 1L<<1, gest_key_relase, cube);
	mlx_hook(cube->win, 2, 1L<<0, gest_key_press, cube);
	// mlx_key_hook(cube->win, tmp, cube);
	mlx_loop(cube->mlx);


	return 0;
}
