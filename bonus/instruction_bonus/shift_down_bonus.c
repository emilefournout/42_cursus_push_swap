/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:55 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:59:41 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	double_shift_down_bonus(t_list **stack_a, t_list **stack_b)
{
	shift_down_bonus(stack_a);
	shift_down_bonus(stack_b);
	return (0);
}

int	shift_down_bonus(t_list **lst)
{
	t_list	*first_node;
	t_list	*node_before_last_node;
	t_list	*last_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (0);
	last_node = ft_lstlast(first_node);
	node_before_last_node = node_before_last(first_node, last_node);
	last_node->next = first_node;
	node_before_last_node->next = NULL;
	*lst = last_node;
	return (0);
}
