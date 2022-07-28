/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:55 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:45:25 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_shift_down(t_list **stack_a, t_list **stack_b)
{
	if (shift_down(stack_a) == 0 && shift_down(stack_b) == 0)
		return (0);
	return (1);
}

t_list	*node_before_last(t_list *first, t_list *last)
{
	while (first->next != last)
		first = first->next;
	return (first);
}

int	shift_down(t_list **lst)
{
	t_list	*first_node;
	t_list	*node_before_last_node;
	t_list	*last_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (1);
	last_node = ft_lstlast(first_node);
	node_before_last_node = node_before_last(first_node, last_node);
	last_node->next = first_node;
	node_before_last_node->next = NULL;
	*lst = last_node;
	return (0);
}
