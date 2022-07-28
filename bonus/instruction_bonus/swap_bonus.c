/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:09:02 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:59:26 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	double_swap_bonus(t_list **stack_a, t_list **stack_b)
{
	swap_bonus(stack_a);
	swap_bonus(stack_b);
	return (0);
}

int	swap_bonus(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (0);
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*lst = second_node;
	return (0);
}
