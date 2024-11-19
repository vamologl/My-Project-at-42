/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:48:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:00 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_char_door(t_cube *cube)
{
	int	x;
	int	y;

	y = get_start_map(cube);
	while (cube->worldmap[y])
	{
		x = 0;
		while (cube->worldmap[y][x])
		{
			if (cube->worldmap[y][x] == 'D')
				return (1);
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	init_map2(t_cube *cube)
{
	if (check_symbols(cube) != 0)
		return (ERROR);
	if (check_textures(cube) != 0)
		return (ERROR);
	if (cube->check_door == 1)
	{
		if (cube->door_tex_name == NULL)
			return (ERROR);
	}
	if (check_color(cube) != 0)
		return (ERROR);
	return (VALID);
}

int	init_map(char *s, t_cube *cube)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (check_ext(s, (int)ft_strlen(s)) != 0)
		return (ERROR);
	if (fd == -1)
		return (ERROR);
	cube->worldmap = build_map(fd);
	if (!cube->worldmap)
		return (2);
	if (check_char_door(cube) != 0)
		cube->check_door = 1;
	if (get_player_pos(cube) != 0)
		return (ERROR);
	if (checkmap(cube) != 0)
		return (ERROR);
	if (init_map2(cube) != VALID)
		return (ERROR);
	return (VALID);
}

int	init_game(t_cube *cube)
{
	cube->player->forward = 0;
	cube->player->side = 0;
	cube->player->rot = 0;
	cube->player->movespeed = 0.0075;
	cube->player->rotspeed = 0.01;
	cube->mlx = mlx_init();
	load_xpm_texture(cube->we_tex_name, cube);
	load_xpm_texture1(cube->no_tex_name, cube);
	load_xpm_texture2(cube->ea_tex_name, cube);
	load_xpm_texture3(cube->so_tex_name, cube);
	if (cube->check_door == 1)
		load_xpm_texture4(cube->door_tex_name, cube);
	if (check_texture_size(cube) != VALID)
		ft_gest_exit_windowless(cube);
	cube->win = mlx_new_window(cube->mlx, SCREENWIDTH,
			SCREENHEIGHT, "Cube3D");
	cube->loaded = 1;
	return (VALID);
}

int	main(int ac, char **av)
{
	t_cube	*cube;

	cube = gc_alloc(sizeof(t_cube), 6);
	cube->loaded = 0;
	cube->player = gc_alloc(sizeof(t_player), 2);
	if (ac != 2)
		return (1);
	if (init_map(av[1], cube) != 0)
	{
		printf("Error, map init failed\n");
		error_initmap_free(cube);
	}
	if (init_game(cube) != VALID)
		ft_gest_exit(cube);
	draw_loop(cube);
	mlx_loop_hook(cube->mlx, draw_loop, cube);
	mlx_hook(cube->win, 17, 1L << 17, ft_gest_exit, cube);
	mlx_hook(cube->win, 6, 1L << 6, gest_mouse_mov, cube);
	mlx_hook(cube->win, 3, 1L << 1, gest_key_relase, cube);
	mlx_hook(cube->win, 2, 1L << 0, gest_key_press, cube);
	mlx_loop(cube->mlx);
	return (0);
}
