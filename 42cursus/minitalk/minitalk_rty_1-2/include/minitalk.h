/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:01:20 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/17 09:11:08 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include <unistd.h>
# include "../storage/ft_printf/ft_printf.h"

typedef struct s_minitalk
{
	struct sigaction	sa;
	char				c;
	char				*str;
	char				*stor;
}				t_minitalk;

int		isnum(char *s);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s);
void	end_str(char *str, char *stor);

#endif
