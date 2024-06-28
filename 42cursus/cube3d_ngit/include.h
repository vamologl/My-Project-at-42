/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:37:46 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/28 13:03:46 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128

# endif

# define ERROR 1
# define VALID 0

# define screenWidth 800
# define screenHeight 600

# define texHeight 64
# define texWidth 64

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

/* -- struct -- */
typedef struct s_gc

{
	int				imp;
	void			*alloc;
	size_t			size;
	struct s_gc		*next;
}	t_gc;

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

	int	texNum;
}               t_raycast;

typedef struct s_player
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;

	int	forward;
	int	side;
	int	rot;

	double moveSpeed;
	double rotSpeed;
}				t_player;

typedef struct s_cube
{
	void *mlx;
	void *win;
	void *img;
	char *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;

	int	**texture;
	
	char **worldMap;
	int mapWidth;
	int mapHeight;

	int fd_no_tex;
	int fd_so_tex;
	int fd_we_tex;
	int fd_ea_tex;

	int color_c;
	int color_f;


	t_player    *player;
}               t_cube;

void	*gc_alloc(size_t sz, int imp);
void	gc_free(void *ptr);
void	gc_free_p(int imp);
void	gc_free_all(void);
void	print_addr(void);
char	*ft_strdup_gc(const char *s, int imp);
char	*ft_strjoin_gc(char const *s1, char const *s2, int imp);
void	*ft_calloc_gc(size_t nmemb, size_t size, int imp);
char	**ft_split_gc(char const *s, char c, int imp);
char	*ft_substr_gc(char const *s, unsigned int start, size_t len, int imp);

/* -- Get Next Line --*/
char	*get_next_line(int fd);
char	**make_map(int fd);
void	print_tab(char **av);
void	free_tab(char **tab);
int	    tablen(char **tab);

void	draw_line(t_cube *cube, int x, int drawStart, int drawEnd, int color);
void	init_raycast(t_raycast *ray, int x, t_cube *cube);
void	color(t_raycast *ray, t_cube *cube);
void	cast_ray(t_cube *cube, int x);
int	    draw_loop(t_cube *cube);

int 	gest_key_press(int keycode, t_cube *cube);
int	    gest_key_relase(int keycode, t_cube *cube);
int	    movement(t_cube *cube);

int     check_symbols(t_cube *cube);
int     checkmap(t_cube *cube);
int     check_ext(char *s, int len);
char	*ft_sstrndup(char *s, int n, int start, int imp);

int		ctorgb(char *str);
int		htoi(const char *s);
int		get_color(char *s);


#endif