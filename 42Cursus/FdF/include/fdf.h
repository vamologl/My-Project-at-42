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

# define BUFF_SIZE 8
# define FD_SIZE 4096

//#include "minilibx/mlx.h"
//# include "libft/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>


typedef struct
{
	int	width;
	int	height;
	int	**z_matrix;

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


void	fill_matrix(int *z_line, char *line);
void	read_file(char *fname, fdf *data);

int		get_width(char *fname);
int		get_height(char *fname);
int		ft_nbword(char const *s, char c);
int		ft_lword(char const *s, char c, int i);
int		ft_atoi(const char *str);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);
int		get_next_line(const int fd, char **line);

char	*ft_next(char *b);
char	*ft_free(char *buffer, char *buf);
char	*ft_line(char *b);
char	*gnl_read_file(int fd, char *res);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strnew(size_t size);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_strdel(char **as);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

int		output(char **s, char **line, int ret, int fd);

int		words(char const *str, char c);

#endif