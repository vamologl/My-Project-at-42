/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:32 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/30 15:28:06 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--include--*/
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>

# include "../libft/libft.h"
# include "../gc/gc.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

/*--macro--*/
# define BUFFER_SZ 8192

/*--variable global--*/
extern volatile sig_atomic_t	g_signal;

/*--struct--*/
typedef struct s_pipeline
{
	pid_t	pid;
	int		prev_pipe_read;
	int		pipefd[2];
	int		i;
}				t_pipeline;

typedef struct s_base
{
	char		***tableau;
	char		*input;
	char		*user;
	char		*cur_pwd;
	char		**env_old;
	char		*output_file;
	char		*command;
	char		*env_path;
	int			terminal_in;
	int			terminal_out;
	int			fd_out;
	int			fd_in;
	int			flag_redir;
	int			loop;
	int			tablen;
	int			flag_error_redir;
	int			return_value;
	int			return_value_flag;
	int			dl_redir;
	pid_t		tmp_pid;
	t_pipeline	*pipe;
}				t_base;

/*---builtin---*/
int		ft_export(t_base *base, int j);
int		ft_is_num(char *str);
int		get_pwd(t_base *base);
void	sorted(int argc, char **argv, t_base *base);
void	add_env_old(char **env_old, char *str);
void	echo_putstr_fd(char *s, int fd);
void	ft_exit_alt(t_base *base, int i);
void	ft_unset(t_base *base, int j);
void	own_cd(char *str, t_base *base);
void	own_echo(t_base *base, int k);
void	own_env(t_base *base, int i);
void	remove_old_env(t_base *base, char *var_name);
void	update_env_old(t_base *base, char *new_value);
void	write_echo(t_base *base, int k);
void	ft_gc_free(void);
void	free_base(t_base *base);

/*---exec---*/
char	*get_my_env(char *name, char **env);
int		ft_tablen(char **tab);
int		ft_exec_prog(char **av, t_base *base);
int		ft_spe_execve(char **av, char **tab, t_base *base);
int		is_there_redir(char **s);

/*---exit---*/
int		ft_check_char(char *s, t_base *base);
void	ft_exit(t_base *base, int i);
void	message(t_base *base);
void	exit_prog(int i, void *ptr, t_base *base);

/*---gbc---*/
char	*ft_itoa_gc(int n, int imp);
char	*ft_strdup_gc(const char *s, int imp);
char	*ft_strndup_gc(char *s, int n, int imp);
char	*ft_strjoin_gc(char const *s1, char const *s2, int imp);
char	**ft_split_gc(char const *s, char c, int imp);
void	*ft_calloc_gc(size_t nmemb, size_t size, int imp);
void	*gc_alloc(size_t sz, int imp);

/*---parser---*/
char	*correct_input_for_parser(char *s);
char	*ft_skip_spaces(char *s);
char	*ft_sstrndup(char *s, int n, int start, int imp);
char	*ft_strndup(char *s, int n);
char	*get_path_tab(char *input, char **env);
char	*init_input(char *s);
char	*modif_token(char *s, t_base *base);
char	**ft_super_split(char *s);
char	***ft_ultra_split(char *s, t_base *base);
char	***pre_build_tab(t_base *base, char *s);
int		check_quote(const char *s, int i, char c);
int		chk_quote(char *s);
int		correct_redirection_len(char *av);
int		find_pipe(char *s);
int		ft_get_word_size(const char *s);
int		ft_find_redirection(char *s);
int		ft_super_countwords(const char *s);
int		hm_pipe(char *s);
int		hm_ultra_tab(char ***tab);
int		is_there_char(char *s, char c);
int		nb_char(char *s);
int		no_command(char **av);
int		skip_whitespace(char *string, int i);
int		tablen_pipe(char **tab, int i);
int		get_file_inpout(t_base *base, char **av, int i);
int		check_illegal_redir(char **av, t_base *base);
void	get_command(char ***tableau, int j, t_base *base);
void	gest_dollar_multipipe(t_base *base);
void	gest_pipe_and_redir2(t_base *base, char ***command, int i);
void	get_input_tab(t_base *base, int i);
void	get_input_tab_spe(t_base *base, char **command);
void	parser(t_base *base);

/*---redir_pipe---*/
char	*correct_pipe_for_parser(char *s);
char	**get_exec(char **tab);
int		ft_left_redir(char **av, t_base *base, int j);
int		here_doc(char *eof, t_base *base);
int		only_one_redir(char **s);
int		only_one_type_redir(char **tab);
void	child_routin(int pipefd[2], char *eof, char *buf, t_base *base);
void	execute_pipeline(char ***command, int nb_cmds, t_base *base);
void	ft_basic_redir(char **av, t_base *base, int j);
void	ft_double_lredir(t_base *base, int j);
void	ft_double_redir(char **av, t_base *base, int j);
void	multi_redir(char **str, t_base *base, int j);
void	set_output(char **str, t_base *base);

/*---struct---*/
void	init_base(t_base *base, char **env);
void	gest_shlvl(t_base *base);

/*---user---*/
void	init_user(t_base *base);

/*---Utils---*/
char	*get_next_line(int fd);
char	*get_var_env(char **env, char *name);
int		check_if_storable(char *s);
int		find_that_char(char *s, char c);
int		ft_is_that_char(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		is_almost_writable(int c);
int		is_empty(char *s);
size_t	ft_strclen(char *s, char c);

#endif
