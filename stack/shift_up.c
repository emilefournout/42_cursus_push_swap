/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:59 by efournou          #+#    #+#             */
/*   Updated: 2022/07/18 06:28:48 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_shift_up(t_list **stack_a, t_list **stack_b)
{
	if (shift_up(stack_a) == 0 && shift_up(stack_b) == 0)
		return (0);
	return (1);
}

int	shift_up(t_list **lst)
{
	t_list	*first_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return (1);
	*lst = first_node->next;
	ft_lstlast(first_node)->next = first_node;
	first_node->next = NULL;
	return (0);
}
