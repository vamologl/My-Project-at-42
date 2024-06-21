/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:41:19 by vamologl          #+#    #+#             */
/*   Updated: 2023/12/04 10:41:23 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

/*fonction*/
void	swap(t_stack **head);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

/*move-a*/
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);

/*move-b*/
void	sb(t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rb(t_stack **b);
void	rrb(t_stack **b);

/*move-a-b*/
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*stack-utils*/
long	ft_atol(const char *str);
void	add_node(t_stack **stack, int nbr);
void	initial_stack(t_stack **a, char **argv, bool flag_argc_2);

/*stack-control*/
t_stack	*find_last(t_stack *head);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
int		stack_len(t_stack *stack);

/*error*/
void	free_matrix(char **argv);
void	free_stack(t_stack **stack);
void	error_free(t_stack **a, char **argv, bool flag_argc_2);
int		error_syntax(char *str_nbr);
int		error_repetition(t_stack *a, int nbr);

/*function-utils*/
char	**ft_split(char *str, char separator);

/*mini-sort*/
bool	is_sorted(t_stack *stack);
void	mini_sort(t_stack **a);
void	handle_five(t_stack **a, t_stack **b);

/*Bigalgo_utils*/
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	cheapest(t_stack *b);
void	initial_nodes(t_stack *a, t_stack *b);

/*Bigalgo*/
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	push_swap(t_stack **a, t_stack **b);

#endif
