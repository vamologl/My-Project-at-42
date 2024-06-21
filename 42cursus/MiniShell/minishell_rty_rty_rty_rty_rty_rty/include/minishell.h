/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:06:32 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/12 13:27:41 by vamologl         ###   ########.fr       */
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
extern volatile int	g_return_code;

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
	char		*user_store;
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
	int			dl_redir_check_break;
	int			error_parse;
	int			here_doc;
	int			info_signal;
	int			prev_ret_code;
	pid_t		tmp_pid;
	int			add_heredoc;
	char		*path_heredoc;
	int			quotes_here_doc;
	int			heredoc_error;
	t_pipeline	*pipe;
}				t_base;

/*--- builtin ---*/
	/*-- echo --*/
		/*- echo write-*/
void		echo_putstr_fd(char *s, int fd);
void		write_echo(t_base *base, int k);
void		write_echo_alt(t_base *base, int i, int flag, int k);

		/*- echo -*/
int			is_string_printable(char *s);
void		own_echo(t_base *base, int k);

	/*-- exit --*/
		/*- exit alter -*/
void		ft_exit_alt2(t_base *base);
void		close_all(int mode);
void		ft_exit_alt(t_base *base, int i, int mode, int ret);

		/*- exit utils -*/
void		message(t_base *base);
int			basic_exit(t_base *base, int i, long long tmp, int ret);

		/*- ft_exit -*/
void		free_base(t_base *base);
int			ft_is_num(char *str);
void		ft_exit(t_base *base, int i);

	/*-- export --*/
		/*-- export_env --*/
void		update_env_old(t_base *base, char *new_value);
char		*get_var_env(char **env, char *name);

		/*-- export_sort --*/
void		sorted(int argc, char **tab, t_base *base);

		/*-- export --*/
void		add_env_old(char **env_old, char *str);
int			ft_export(t_base *base, int j);

	/*-- command --*/
void		get_command(char ***tableau, int j, t_base *base);

	/*-- cd --*/
void		own_cd(int k, t_base *base);

	/*-- env --*/
void		own_env(t_base *base, int i);

	/*-- pwd --*/
int			get_pwd(t_base *base, int mode);
char		*return_pwd(void);

	/*-- unset --*/
void		remove_old_env(t_base *base, char *var_name);
void		ft_unset(t_base *base, int j);

/*--- check ---*/
	/*-- check_char --*/
int			nb_char(char *s);
int			chk_quote(char *s);
int			ft_is_that_char(const char *s, int c);

	/*-- check_char2 --*/
int			is_empty(char *s);
size_t		ft_strclen(char *s, char c);
int			check_if_storable(char *s);
int			ft_strcmp(char *s1, char *s2);

	/*-- check_more_redir --*/
int			ft_find_redirection(char *s);

	/*-- check_parser --*/
int			check_parser(char *s, t_base *base);

	/*-- check_redir --*/
int			check_redir_file(char *s, t_base *base);
int			is_there_redir(char **s);

	/*-- check_string_exist --*/
int			is_there_char(char *s, char c);
void		get_input_tab(t_base *base, int i);
int			check_empty_tab(char **tab);
int			no_command(char **av);
int			check_pipe(char *s);

/*--- exec ---*/
	/*-- exec_build --*/
char		*get_path_tab(char *input, char **env);
int			check_space_in_token_one(char *s);
char		**build_full_exec_command(char **av, t_base *base);

	/*-- exec --*/
int			ft_exec_prog(char **av, t_base *base);
int			ft_spe_execve(char **av, char **tab, t_base *base, int status);

/*--- gc ---*/
	/*-- gc_split --*/
char		**ft_split_gc(char const *s, char c, int imp);

	/*-- gc_utils --*/
char		*ft_strdup_gc(const char *s, int imp);
char		*ft_strjoin_gc(char const *s1, char const *s2, int imp);
void		*ft_calloc_gc(size_t nmemb, size_t size, int imp);

	/*-- itoa_gc --*/
char		*ft_itoa_gc(int n, int imp);
long long	ft_long_atoi(const char *str);

/*--- gest ---*/
	/*-- gest_char_token --*/
int			hm_pipe(char *s);
int			find_pipe(char *s);
int			tablen_pipe(char **tab, int i);
char		***pre_build_tab(t_base *base, char *s);

	/*-- gest_pipeline --*/
void		execute_pipeline(char ***command, int nb_cmds, t_base *base);

	/*-- gest_struct --*/
void		init_path(t_base *base);
void		init_base(t_base *base, char **env);
void		gest_shlvl(t_base *base);
void		check_loop_start(t_base *base);

	/*-- gest_tab_command --*/
char		**remove_null_in_tab(char **tab);

	/*-- gest_token --*/
char		***ft_ultra_split(char *s, t_base *base);
char		***gest_dollar_multipipe(t_base *base, int j);

	/*-- get_next_line --*/
char		*get_next_line(int fd);

	/*-- parse --*/
void		gest_pipe_and_redir2(t_base *base, char ***command, int i);
void		parser(t_base *base);

	/*-- replace_dollar_token --*/
char		*modif_token(char *s, t_base *base);

	/*-- string_gest --*/
char		*ft_sstrndup(char *s, int n, int start, int imp);
char		*ft_strndup(char *s, int n);
int			hm_ultra_tab(char ***tab);

	/*-- utils --*/
int			ft_tablen(char **tab);
char		*get_my_env(char *name, char **env);
int			hm_that_char(char *s, char c);
int			find_that_char(char *s, char c);

/*--- redirection ---*/
	/*-- correct_input_parser --*/
char		*correct_pipe_for_parser(char *s);
char		*correct_input_for_parser(char *s);

	/*-- correct_input_parser2 --*/
int			correct_redirection_len(char *av);
char		*init_input(char *s, t_base *base);

	/*-- here_doc --*/
int			here_doc(char *eof, t_base *base);

	/*-- init_input --*/
char		**get_exec(char **tab);
int			set_input(char **str, t_base *base, int tmp);

	/*-- init_output --*/
void		set_output(char **str, t_base *base);
int			ft_triple_tablen(char ***tab);

/*--- super split ---*/
	/*-- ft_super_split_utils_utils --*/
int			ft_super_countwords(const char *s);
char		*ft_skip_spaces(char *s);
int			ft_get_word_size(const char *s);

	/*-- ft_super_split_utils --*/
char		**ft_super_split(char *s);

/*--- user ---*/
	/*-- user_path --*/
char		*get_correct_path(t_base *base);

	/*-- user --*/
void		init_user(t_base *base);

/*--- signal ---*/
void		set_signal_handlers(void);

#endif
