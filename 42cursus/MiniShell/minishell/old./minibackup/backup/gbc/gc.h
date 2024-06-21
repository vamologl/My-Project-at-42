/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 13:54:33 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// author: BEAUFILS Noah
// date: march/28/2024

#ifndef GC_H
# define GC_H 1

# include <stdlib.h>
# include <stdio.h>

typedef struct s_gc
{
	int				imp;
	void			*alloc;
	size_t			size;
	struct s_gc		*next;
}	t_gc;

void	*gc_alloc( size_t sz, int imp );
void	gc_free( void *ptr );
void	gc_free_p( int imp );
void	gc_free_all( void );
void	print_addr(void);

#endif