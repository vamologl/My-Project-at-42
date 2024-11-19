/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:53:49 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/27 13:54:46 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	free_node( t_gc *node );
t_gc	*ll_add_back( t_gc *lst, t_gc *node );
t_gc	*remove_idx( size_t idx, t_gc *lst );

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
