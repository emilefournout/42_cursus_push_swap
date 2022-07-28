/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:09:02 by efournou          #+#    #+#             */
/*   Updated: 2022/07/18 06:28:35 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_swap(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 0 && swap(stack_b) == 0)
		return (0);
	return (1);
}

int	swap(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (1);
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*lst = second_node;
	return (0);
}
