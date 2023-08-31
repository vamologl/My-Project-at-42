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

//#include "minilibx/mlx.h"
//# include "libft/libft.h"

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>


typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	int		modif_x;
	int		modif_y;

	void	*mlx_ptr;
	void	*win_ptr;
}				fdf;

typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

/*
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;*/

//draw file
void    bresenham(float x, float y, float x1, float y1, fdf *data);
float   mod(float i);
float   max(float a, float b);
void    draw(fdf *data);

//read_file file
void	fill_matrix(int *z_line, char *line);
int	get_height(char *fname);
int	get_width(char *fname);
void	read_file(char *fname, fdf *data);

//utils0
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_nbword(char const *s, char c);
int		ft_lword(char const *s, char c, int i);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//utils1
void	ft_strdel(char **as);
int		appendline(char **s, char **line);
int		output(char **s, char **line, int ret, int fd);
int		get_next_line(const int fd, char **line);
char	*ft_strdup(const char *s);

//utils2
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		words(char const *str, char c);

//utils3
float   maxim(float a, float b);
float   mod(float i);

#endif
