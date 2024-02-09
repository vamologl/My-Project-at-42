/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:22:58 by vamologl          #+#    #+#             */
/*   Updated: 2023/06/19 14:07:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

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
	echap	= 65307,
	left	= 65361,
	down	= 65362,
	right	= 65363,
	up		= 65364,
	etoile	= 65450,
	plus	= 65451,
	moins	= 65453,
	barre	= 65455,
}			t_touche;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		size_win_x;
	int		size_win_y;
	int		zoom;
	int		color;
	int		modif_x;
	int		modif_y;
	float	angle;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*img_buffer;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	float	x;
	float	y;
}				t_fdf;

typedef struct s_coords
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
}				t_coords;

//void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	bresenham2(t_fdf *data, float x1, float y1);
void	draw(t_fdf *data);
void	render(t_fdf *data, int x, int y, int color);
void	img_pix_put(t_fdf *data, int x, int y, int color);
void	img_clear(t_fdf *data);
void	fill_matrix(int *z_line, char *line);
void	read_file(char *fname, t_fdf *data);
int		get_height(char *fname);
int		get_width(char *fname);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_nbword(char const *s, char c);
int		ft_lword(char const *s, char c, int i);
int		ft_atoi(const char *str);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s);
int		appendline(char **s, char **line);
int		output(char **s, char **line, int ret, int fd);
int		get_next_line(const int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		words(char const *str, char c);
float	maxim(float a, float b);
float	mod(float i);
int		set_color(int z);

#endif