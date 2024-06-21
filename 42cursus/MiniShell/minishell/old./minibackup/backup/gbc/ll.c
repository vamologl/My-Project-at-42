/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:50 by vamologl          #+#    #+#             */
/*   Updated: 2024/04/17 13:56:44 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// author: BEAUFILS Noah
// date: march/28/2024

#include "gc.h"

t_gc	*gc_memory(t_gc *node, int code);

void	free_node(t_gc *node)
{
	if (!node)
		return ;
	free(node->alloc);
	free(node);
}

t_gc	*ll_add_back(t_gc *lst, t_gc *node)
{
	t_gc	*new_lst;

	if (!lst)
		return (node);
	new_lst = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
	return (new_lst);
}

t_gc	*remove_idx(size_t idx, t_gc *lst)
{
	t_gc		*past;
	t_gc		*new_lst;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	else if (idx == 0)
	{
		new_lst = lst->next;
		free_node(lst);
		return (new_lst);
	}
	while (idx)
	{
		past = lst;
		lst = lst->next;
		idx--;
	}
	past->next = lst->next;
	free_node(lst);
	return (new_lst);
}

void	print_addr(void)
{
	size_t	blocks;
	size_t	alloc_sz;
	t_gc	*ll;

	blocks = 0;
	alloc_sz = 0;
	ll = gc_memory(NULL, 1);
	printf("\n==%ld== MEMORY CHECKER\n", __STDC_VERSION__);
	while (ll)
	{
		printf("==%ld== block of size %zu\n", __STDC_VERSION__, ll->size);
		printf("==%ld==    Address %p is set as %d\n", __STDC_VERSION__,
			ll->alloc, ll->imp);
		blocks++;
		alloc_sz += ll->size;
		ll = ll->next;
	}
	printf("==%ld==\n", __STDC_VERSION__);
	printf("==%ld==\n", __STDC_VERSION__);
	printf("==%ld== HEAP SUMMARY:\n", __STDC_VERSION__);
	printf("==%ld==    total heap usage %zu bytes in %zu blocks\n",
		__STDC_VERSION__, alloc_sz, blocks);
	printf("==%ld==\n", __STDC_VERSION__);
}
