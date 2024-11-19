/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:32:21 by vamologl          #+#    #+#             */
/*   Updated: 2024/10/01 10:39:09 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define ERROR 1
# define VALID 0
# define SCREENWIDTH 800
# define SCREENHEIGHT 600
# define TEXHEIGHT 64
# define TEXWIDTH 64

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

# include <sys/time.h> // to remove

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
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_raycast;

typedef struct s_texture
{
	void		*img;
	int			*data;
	int			width;
	int			height;
}				t_texture;

typedef struct s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			forward;
	int			side;
	int			rot;
	double		movespeed;
	double		rotspeed;
}				t_player;

typedef struct s_cube
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		**worldmap;
	int			mapwidth;
	int			mapheight;
	int			fd_no_tex;
	char		*no_tex_name;
	int			fd_so_tex;
	char		*so_tex_name;
	int			fd_we_tex;
	char		*we_tex_name;
	int			fd_ea_tex;
	char		*ea_tex_name;
	int			fd_door_tex;
	char		*door_tex_name;
	int			color_c;
	int			color_f;
	int			texnum;
	bool		loaded;
	bool		mouse;
	bool		check_door;
	int			north_animation_frame;
	int			south_animation_frame;
	int			east_animation_frame;
	int			west_animation_frame;
	int			door_animation_frame;
	int			size_map;
	int			start_map;
	int			half_screen;
	t_player	*player;
	t_raycast	*ray;
	t_texture	*texture;
	t_texture	*texture1;
	t_texture	*texture2;
	t_texture	*texture3;
	t_texture	*texture4;
}				t_cube;

void		*gc_alloc(size_t sz, int imp);
void		gc_free(void *ptr);
void		gc_free_p(int imp);
void		gc_free_all(void);
void		print_addr(void);
char		*ft_strdup_gc(const char *s, int imp);
char		*ft_strjoin_gc(char const *s1, char const *s2, int imp);
void		*ft_calloc_gc(size_t nmemb, size_t size, int imp);
char		**ft_split_gc(char const *s, char c, int imp);
char		*ft_substr_gc(char const *s, unsigned int start,
				size_t len, int imp);
char		*get_next_line(int fd);
char		**make_map(int fd);
void		print_tab(char **av);
void		free_tab(char **tab);
int			tablen(char **tab);
void		color(t_raycast *ray, t_cube *cube);
void		cast_ray(t_cube *cube, int x);
int			draw_loop(t_cube *cube);
int			gest_key_press(int keycode, t_cube *cube);
int			gest_key_relase(int keycode, t_cube *cube);
int			movement(t_cube *cube);
int			check_symbols(t_cube *cube);
int			checkmap(t_cube *cube);
int			check_ext(char *s, int len);
char		*ft_sstrndup(char *s, int n, int start, int imp);
int			ctorgb(char *str);
int			htoi(const char *s);
int			get_color(char *s);
int			ft_gest_exit(t_cube *cube);
char		**build_map(int fd);
void		dont_draw_line(t_cube *cube, int x, int y, int color);
void		img_pix_put(t_cube *cube, int x, int y, int color);
int			print_texture(t_cube *cube);
void		draw_line(t_cube *cube, int x, int drawend, int color);
void		get_color_texture(t_cube *cube, int y, int texx, int x);
char		*ft_itoa_base(int value, int base);
void		rotation_plus(t_cube *cube, double olddirx, double oldplanex);
void		rotation_minus(t_cube *cube, double olddirx, double oldplanex);
void		forward(t_cube *cube);
void		side_plus(t_cube *cube);
void		side_minus(t_cube *cube);
void		backward(t_cube *cube);
int			check_direction_player(char c, t_cube *cube);
int			check_textures(t_cube *cube);
bool		set_player_pos(int x, int y, t_cube *cube);
int			ft_strcmp_sl(char *s, char *c);
int			get_start_map(t_cube *cube);
int			heck_symbols(t_cube *cube);
int			check_tab(t_cube *cube, int y);
bool		check_north(t_cube *cube, char *str);
bool		check_south(t_cube *cube, char *str);
bool		check_west(t_cube *cube, char *str);
bool		check_east(t_cube *cube, char *str);
int			check_color(t_cube *cube);
int			gest_mouse_mov(int x, int y, t_cube *cube);
void		forward_doors(t_cube *cube);
void		backward_doors(t_cube *cube);
void		side_minus_doors(t_cube *cube);
void		side_plus_doors(t_cube *cube);
void		error_initmap_free(t_cube *cube, int ret);
void		mov(t_cube *cube);
void		cast_ray5(t_cube *cube);
void		draw_background(t_cube *cube, int y);
bool		check_door_tex(t_cube *cube, char *str);
int			check_door(t_cube *cube);
int			get_player_pos(t_cube *cube);
void		anim_south(t_cube *cube);
void		anim_north(t_cube *cube);
void		anim_east(t_cube *cube);
void		anim_west(t_cube *cube);
void		anim_door(t_cube *cube);
int			check_height_texture(t_cube *cube);
int			check_length_texture(t_cube *cube);
int			check_texture_size(t_cube *cube);
int			ft_gest_exit_windowless(t_cube *cube);
void		minimap(t_cube *cube);
void		draw_cube(t_cube *cube, int x, int y, int color);
void		minimap_door(t_cube *cube, int y, int x);
int			get_color_north(t_cube *cube, int y, int texx);
int			get_color_south(t_cube *cube, int y, int texx);
int			get_color_east(t_cube *cube, int y, int texx);
int			get_color_west(t_cube *cube, int y, int texx);
int			get_color_doors(t_cube *cube, int y, int texx);
int			check_open_door(t_cube *cube);
int			check_close_door(t_cube *cube);
void		check_door_around(t_cube *cube);
int			get_size(t_cube *cube);
int			error_arg(void);
t_texture	*load_xpm_texture(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture1(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture2(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture3(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture4(const char *filepath, t_cube *cube);

#endif