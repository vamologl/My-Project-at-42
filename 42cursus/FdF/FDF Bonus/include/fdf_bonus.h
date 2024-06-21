/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:29:40 by vamologl          #+#    #+#             */
/*   Updated: 2023/10/04 10:29:46 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include "../minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <X11/Xlib.h>

typedef enum e_touch
{
	esc		= 65307,
	left	= 65361,
	down	= 65362,
	right	= 65363,
	up		= 65364,
	star	= 65450,
	add		= 65451,
	minus	= 65453,
	dash	= 65455,
	R_key	= 114,
	W_key	= 119,
	A_key	= 97,
	S_key	= 115,
	D_key	= 100,
	P_key	= 112,
}			t_touche;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	char	*img_buffer;
	int		fd;
	int		bpp;
	int		zoom;
	int		color;
	int		width;
	int		endian;
	int		height;
	int		modif_x;
	int		modif_y;
	int		line_len;
	int		size_win_x;
	int		size_win_y;
	int		**z_matrix;
	float	angle;
	float	tmp_x;
	float	tmp_y;
	int		iso;
}				t_fdf;

void	draw(t_fdf *data);
void	check_empty(void);
void	check_map(char *s);
void	ft_strdel(char **as);
void	print_map(t_fdf *data);
void	img_clear(t_fdf *data);
void	check_ext(char *s, int len);
void	struct_full_init(t_fdf *data);
void	read_file(char *fname, t_fdf *data);
void	fill_matrix(int *z_line, char *line);
void	bresenham(float x1, float y1, t_fdf *data);
void	render(t_fdf *data, int x, int y, int color);
void	img_pix_put(t_fdf *data, int x, int y, int color);
void	isometric(float *x, float *y, int z, t_fdf *data);
char	*ft_strdup(char *s);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		set_color(int z);
int		get_width(char *fname);
int		get_height(char *fname);
int		ft_atoi(const char *str);
int		words(char const *str, char c);
int		ft_nbword(char const *s, char c);
int		appendline(char **s, char **line);
int		ft_lword(char const *s, char c, int i);
int		get_next_line(const int fd, char **line);
int		output(char **s, char **line, int ret, int fd);
size_t	ft_strlen(const char *str);
float	mod(float i);
float	maxim(float a, float b);

void	print_key(t_fdf *data);

#endif
