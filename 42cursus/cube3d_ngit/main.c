/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:48:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/21 15:14:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "include.h"
#include "gc/gc.h"
#include <math.h>

int	key_hook(int keycode, t_cube *cube)
{
	double moveSpeed = 0.2;
	double rotSpeed = 0.03;
	double oldDirX = cube->player->dirX;
	double oldPlaneX = cube->player->planeX;

	dprintf(2, "test - key[%c(%d)]\n", keycode, keycode);

	if (keycode == 65307)
		exit(1);
	if(keycode == 65362 || keycode == 'w') // Up arrow key
	{
		if(cube->worldMap[(int)(cube->player->posX + cube->player->dirX * moveSpeed)][(int)cube->player->posY] == '0')
			cube->player->posX += cube->player->dirX * moveSpeed;
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * moveSpeed)] == '0')
			cube->player->posY += cube->player->dirY * moveSpeed;
	}
	if(keycode == 65364 || keycode == 's') // Down arrow key
	{
		if(cube->worldMap[(int)(cube->player->posX - cube->player->dirX * moveSpeed)][(int)cube->player->posY] == '0')
		{
			cube->player->posX -= cube->player->dirX * moveSpeed;
		}
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * moveSpeed)] == '0')
		{
			cube->player->posY -= cube->player->dirY * moveSpeed;
		}
	}
	if(keycode == 65363 || keycode == 'd') // Right arrow key
	{
		cube->player->dirX = cube->player->dirX * cos(-rotSpeed) - cube->player->dirY * sin(-rotSpeed);
		cube->player->dirY = oldDirX * sin(-rotSpeed) + cube->player->dirY * cos(-rotSpeed);
		cube->player->planeX = cube->player->planeX * cos(-rotSpeed) - cube->player->planeY * sin(-rotSpeed);
		cube->player->planeY = oldPlaneX * sin(-rotSpeed) + cube->player->planeY * cos(-rotSpeed);
	}
	if(keycode == 65361 || keycode == 'a') // left arrow key
	{

		cube->player->dirX = cube->player->dirX * cos(rotSpeed) - cube->player->dirY * sin(rotSpeed);
		cube->player->dirY = oldDirX * sin(rotSpeed) + cube->player->dirY * cos(rotSpeed);
		cube->player->planeX = cube->player->planeX * cos(rotSpeed) - cube->player->planeY * sin(rotSpeed);
		cube->player->planeY = oldPlaneX * sin(rotSpeed) + cube->player->planeY * cos(rotSpeed);
	}
	dprintf(2, "test - key[%c(%d)]\n", keycode, keycode);
	main_loop(cube); 
	return 0;
}



int	init_map(char *s, t_cube *cube)
{
	bool flag;
	int	fd;
	int	x;
	int y;
	
	flag = false;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (1); // error file
	cube->worldMap = make_map(fd);
	// check walls here
	if (!cube->worldMap)
		return (2);
	y = 0;
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
					cube->player->posX = x;
					cube->player->posY = y;
					flag = true;
				}
				else if (flag == true)
					return (1);
			}
			x++;
		}
		y++;
	}
	if (!flag)
	{
		printf("test error - no player\n");
		return (3); // No player 
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_cube *cube;
	
	cube = malloc(sizeof(t_cube));
	cube->player = malloc(sizeof(t_player));
	if (ac != 2) // check arg map
		return (1);
	if (init_map(av[1], cube) != 0) // initialize map
		return (2);

	// cube->player->posX = 20; // pos
	// cube->player->posY = 12; // posY
	cube->player->dirX = -1; // camera direction
	cube->player->dirY = 0;
	cube->player->planeX = 0.0; // fov ?
	cube->player->planeY = 0.66;

	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, screenWidth, screenHeight, "cube3d | broken");
	main_loop(cube);
	// mlx_mouse_hook(cube->win, key_hook, cube);
	mlx_hook(cube->win, 17, 1L << 17, key_hook, cube);
	mlx_key_hook(cube->win, key_hook, cube);
	mlx_loop(cube->mlx);
	return 0;
}
