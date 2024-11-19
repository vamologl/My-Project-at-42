/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:50 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/27 13:54:52 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

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
