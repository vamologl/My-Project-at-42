/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:55:34 by vamologl          #+#    #+#             */
/*   Updated: 2023/08/14 08:00:05 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>

/*stack*/
typedef struct
{
    int    value;
    struct stack* next;
}                stack; 


typedef struct s_list
{
	int	indx;
	int	val;
	struct s_list	*next;
}				t_list;



struct test_stack {
	int	indx;
	int	val;
	int	**stack;
};

int	ft_atoi(const char *str);

#endif
