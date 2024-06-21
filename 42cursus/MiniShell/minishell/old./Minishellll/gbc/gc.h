// author: BEAUFILS Noah
// date: march/28/2024

#ifndef GC_H
# define GC_H 1

# include <stdlib.h>	/* memory allocation */
# include <stdio.h>		/* I/O functions */

typedef struct s_gc
{
	int				imp;		// importance
	void			*alloc;		// the allocated memory
	size_t			size;		// the size of the allocated memory
	struct s_gc		*next;		// a pointer to the next node
}	t_gc;

/* allocate a block of size <sz>, set it importance and stores it in the list */
void	*gc_alloc( size_t sz, int imp );

/* free the given address and removes it from the list */
void	gc_free( void *ptr );

/* free all blocs of the given importance and remove them from the list */
void	gc_free_p( int imp );

/* free all blocks and set list to null */
void	gc_free_all( void );

/* show all the currently allocated blocks in the list and their information */
void	print_addr(void);

#endif /* gc.h */