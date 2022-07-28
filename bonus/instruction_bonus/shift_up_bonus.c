/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:59 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:59:28 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	double_shift_up_bonus(t_list **stack_a, t_list **stack_b)
{
	shift_up_bonus(stack_a);
	shift_up_bonus(stack_b);
	return (0);
}

int	shift_up_bonus(t_list **lst)
{
	t_list	*first_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (0);
	*lst = first_node->next;
	ft_lstlast(first_node)->next = first_node;
	first_node->next = NULL;
	return (0);
}
