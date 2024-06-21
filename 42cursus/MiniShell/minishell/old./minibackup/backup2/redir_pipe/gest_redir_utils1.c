/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_redir_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:07 by thlefebv          #+#    #+#             */
/*   Updated: 2024/04/22 15:36:12 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int g_signal;

int	only_one_type_redir(char **tab)
{
	int	i;
	int	tmp_redir;

	i = 0;
	tmp_redir = -1;
	while (tab[i] && tmp_redir == -1)
	{
		if (ft_find_redirection(tab[i]) == 1)
			tmp_redir = 1;
		else if (ft_find_redirection(tab[i]) == 2)
			tmp_redir = 2;
		else if (ft_find_redirection(tab[i]) == 3)
			tmp_redir = 3;
		i++;
	}
	while (tab[i])
	{
		if (ft_find_redirection(tab[i]) != 0
			&& ft_find_redirection(tab[i]) != tmp_redir)
			return (0);
		i++;
	}
	return (1);
}

// int	here_doc(char *eof, t_base *base)
// {
// 	char	*buf;
// 	pid_t	pid;
// 	int		pipefd[2];

// 	(void)base;
// 	buf = NULL;
// 	if (pipe(pipefd) == -1)
// 		return (-1);
// 	pid = fork();
// 	if (pid == -1)
// 		return (-1);
// 	if (pid == 0)
// 		child_routin(pipefd, eof, buf, base);
// 	close(pipefd[1]);
// 	base->tmp_pid = pid;
// 	base->return_value = waitpid(pid, NULL, 0);
// 	return (pipefd[0]);
// }


// void	child_routin(int pipefd[2], char *eof, char *buf, t_base *base)
// {
// 	int	nb;

// 	(void)base;
// 	close(pipefd[0]);
// 	buf = gc_alloc(sizeof(char **) + BUFFER_SZ, -42);
// 	while (buf && g_signal == 0)
// 	{
// 		write(1, "> ", 2);
// 		nb = read(0, buf, BUFFER_SZ);
// 		if (nb == -1)
// 		{	
// 			perror("here_doc");
// 			continue ;
// 		}
// 		if (buf)
// 			buf[nb - 1] = 0;
// 		if (ft_strcmp(eof, buf) == 0)
// 			break ;
// 		write(pipefd[1], buf, ft_strlen(buf));
// 		write(pipefd[1], "\n", 1);
// 	}
// 	close(pipefd[1]);
// 	gc_free_all();
// 	exit(-2);
// }

// void	here_doc(char *eof, t_base *base)
// {
// 	(void)base;
// 	int		greg;
// 	int		nb;
// 	char	*buf;
	
// 	buf = NULL;
// 	greg = open("./Utils/.redir_buf.temp" ,O_WRONLY | O_CREAT | O_TRUNC , 0644);
// 	if (!greg)
// 		return ;
// 	while (g_signal == 0)
// 	{
// 		buf = readline("> ");
// 		if (buf == NULL)
// 			break;
// 		printf("[%s - buffer]\n", buf);
// 		if (ft_strcmp(eof, buf) == 0)
// 			break ;
// 		nb = ft_strlen(buf);
// 		write(greg, buf, ft_strlen(buf));
// 		write(greg, "\n", 1);
// 		if (buf)
// 			free(buf);
// 	}
// 	if (buf)
// 		free(buf);
// 	dup2(greg, base->fd_in);
// 	return ;
// }

/*----------------------------------*/


char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_next(char *b)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = 0;
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

char	*ft_line(char *b)
{
	char	*line;
	int		i;

	i = 0;
	if (!b[i])
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

char	*read_file(int fd, char *res)
{
	char	*b;
	int		b_rd;

	if (!res)
		res = ft_calloc(1, 1);
	b = ft_calloc(4096 + 1, sizeof(char));
	b_rd = 1;
	while (b_rd > 0)
	{
		b_rd = read(fd, b, 4096);
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

	if (fd < 0 || 4096 <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	b = read_file(fd, b);
	if (!b)
		return (NULL);
	l = ft_line(b);
	b = ft_next(b);
	return (l);
}

/*----------------------------------*/

int here_doc(char *eof, t_base *base)
{
    char *buf;
	(void)base;
	int tmp = open("./Utils/.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);


    buf = NULL;
    if (!eof)
        return (-1);
    printf("eof = %s\n", eof);
    while (g_signal == 0) 
	{ 
        write(1, "> ", 2);
        buf = get_next_line(STDIN_FILENO);
        if (!buf)
            break;
        if (strncmp(eof, buf, strlen(buf) - 1) == 0)
            break;
        write(tmp, buf, strlen(buf));
        if (buf)
            free(buf);
    }
    if (buf)
        free(buf);
    return (0);
}
