// author: BEAUFILS Noah
// date: march/28/2024

#include "gc.h"

/////// linked list functions prototypes ///////
void	free_node( t_gc *node );
t_gc	*ll_add_back( t_gc *lst, t_gc *node );
t_gc	*remove_idx( size_t idx, t_gc *lst );
////////////////////////////////////////////////

/*
	gc_memory(null, 1) -> return the list's address
	gc_memory(addr, 1) -> add <addr> to the end of list
	gc_memory(addr/null, 0) -> change <lst> by <addr>
*/

t_gc	*gc_memory(t_gc *node, int code)
{
	static t_gc	*ll;

	if (code == 0 || ll == NULL)
		ll = node;
	else if (node != NULL)
		ll_add_back(ll, node);
	return (ll);
}

void	gc_free_all(void)
{
	t_gc	*lst;
	t_gc	*tmp;

	lst = gc_memory(NULL, 1);
	while (lst)
	{
		tmp = lst->next;
		free_node(lst);
		lst = tmp;
	}
	gc_memory(NULL, 0);
}

void	gc_free(void *ptr)
{
	int		idx;
	t_gc	*lst;

	idx = 0;
	lst = gc_memory(NULL, 1);
	while (lst)
	{
		if (lst->alloc == ptr)
			break ;
		lst = lst->next;
		idx++;
	}
	if (!lst)
		return ;
	gc_memory(remove_idx(idx, gc_memory(NULL, 1)), 0);
}

void	gc_free_p(int imp)
{
	t_gc	*new_lst;
	t_gc	*lst;
	t_gc	*tmp;

	new_lst = NULL;
	lst = gc_memory(NULL, 1);
	while (lst)
	{
		tmp = lst->next;
		lst->next = NULL;
		if (lst->imp == imp)
			free_node(lst);
		else
			new_lst = ll_add_back(new_lst, lst);
		lst = tmp;
	}
	gc_memory(new_lst, 0);
}

void	*gc_alloc(size_t sz, int imp)
{
	size_t		i;
	t_gc		*node;

	i = 0;
	node = malloc(sizeof(t_gc));
	if (!node)
		return (NULL);
	node->imp = imp;
	node->size = sz;
	node->next = NULL;
	node->alloc = malloc(sz);
	if (!node->alloc)
	{
		free(node);
		return (NULL);
	}
	while (i < sz)
		*(unsigned char *)(node->alloc + i++) = 0;
	gc_memory(node, 1);
	return (node->alloc);
}
