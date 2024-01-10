#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

# endif

/*---------------------------*/

size_t	ft_strlen(char *s);
void	*calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t max);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

/*---------------------------*/

char	*ft_next(char *b);
char	*ft_free(char *buffer, char *buf);
char	*ft_line(char *b);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

/*---------------------------*/

void	ft_bzero(void *s, size_t max)
{
	unsigned char	*c;
	size_t		i = 0;

	c = s;
	while (i++ < max)
		*c++ = 0;
}

size_t	ft_strlen(char *s)
{
	size_t	i = 0;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i_b = 0;
	int	j = 0;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char *) * ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (joined != NULL)
	{
		while (s1[i_b] != '\0')
		{
			joined[j] = s1[i_b];
			j++;
			i_b++;
		}
		i_b = 0;
		while (s2[i_b] != '\0')
		{
			joined[j] = s2[i_b];
			j++;
			i_b++;
		}
	}
	joined[j] = '\0';
	return (joined);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr != NULL)
		ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

char	*ft_line(char *b)
{
	char	*line;
	int i = 0;

	if (!b [i])
		return (NULL);
	while (b[i] && b[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (b[i] && b[i] != '\n')
	{
		line[i] = b[i];
		i++;
	}
	if (b[i] && b[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *b)
{
	int	i = 0;
	int	j = 0;
	char	*l;

	while (b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free(b);
		return (NULL);
	}
	l = ft_calloc((ft_strlen(b) - i + 1), sizeof(char));
	i++;
	while (b[i])
		l[j++] = b[i++];
	free(b);
	return (l);
}

char	*read_file(int fd, char *res)
{
	char	*b;
	int	b_rd;
	if (!res)
		res = calloc(1, 1);
	b = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_rd = 1;
	while (b_rd > 0)
	{
		b_rd = read(fd, b, BUFFER_SIZE);
		if (b_rd == -1)
		{
			free(b);
			return (NULL);
		}
		b[b_rd] = 0;
		res = ft_free(res, b);
		if (ft_strchr(b, '\n'))
			b_rd = -1;
	}
	free(b);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	b = read_file(fd, b);
	if (!b)
		return (NULL);
	l = ft_line(b);
	b = ft_next(b);
	return (l);
}
