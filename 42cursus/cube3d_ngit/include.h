/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:37:46 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/21 14:14:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128

# endif

# define screenWidth 960
# define screenHeight 540
// # define mapWidth 24
// # define mapHeight 24

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "gc/gc.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

/* -- struct -- */

typedef struct s_raycast
{
    double cameraX;
    double rayDirX;
    double rayDirY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int mapX;
    int mapY;
    int stepX;
    int stepY;
    int hit;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int color;
}               t_raycast;

typedef struct s_player
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
}               t_player;

typedef struct s_cube
{
    void *mlx;
    void *win;
    void *img;
    char *data_addr;
    int bits_per_pixel;
    int size_line;
    int endian;
    char **worldMap;
    
    int mapWidth;
    int mapHeight;

    t_player    *player;
}               t_cube;

/* -- Get Next Line --*/
char	*get_next_line(int fd);

char	**make_map(int fd);
void	print_tab(char **av);
int	tablen(char **tab);
void	free_tab(char **tab);

void	draw_line(t_cube *cube, int x, int drawStart, int drawEnd, int color);
void	init_raycast(t_raycast *ray, int x, t_cube *cube);
void	color(t_raycast *ray, t_cube *cube);
void	cast_ray(t_cube *cube, int x);
int	    main_loop(t_cube *cube);



/* -- -- */
#endif