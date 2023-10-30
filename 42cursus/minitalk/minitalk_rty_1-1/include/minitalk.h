/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypages <ypages@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:35:06 by ypages            #+#    #+#             */
/*   Updated: 2023/01/25 00:11:32 by ypages           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void     (*sa_restorer)(void);
           };
*/
#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include<limits.h>

typedef struct s_message
{
	char				c;
	struct s_message	*next;
}				t_message;

typedef struct s_vars
{
	struct sigaction	*sa;
	unsigned long int	ms_int;	
	int					is_init;
	int					s_pid;
	int					c_pid;
	int					size;
	int					ms_bits;
	int					*ts_bits;
	int					cb_nbr;
	int					c_nbr;
	int					c_int;
	int					*c_bits;
	char				*arg;
	t_message			*message;
	t_message			**h_message;
}				t_vars;

// VARS INIT
t_vars					*vars(void);
//UTILS CLIENT 
int						put_mess(char *str);
void					ctoo(char c);
void					itoo(int d);
int						put_size(char *str);
//UTILS SERVER
void					check_pid(int pid, siginfo_t *info);
int						check_signal(int signum);
void					free_all(void);
void					del_message(t_message *list);
void					bye(void);
int						btoi(int *tab, int limit);
int						ft_lstsize_m(t_message *lst);
t_message				*ft_lstlast_m(t_message *lst);
void					ft_lstadd_back_m(t_message **alst, t_message *new);
void					print_message(t_message *head);
#endif
