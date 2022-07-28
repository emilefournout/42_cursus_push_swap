/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:07:40 by efournou          #+#    #+#             */
/*   Updated: 2022/07/28 06:53:04 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_list_reverse_sorted(t_list *stack_a)
{
	if (stack_a == (void *)0)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->content < stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static void	empty_stack_b_radix(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

static void	sort_stack_a_radix(struct s_stack stack, int num_pos, int argc,
		int last_sort_checker)
{
	int	node_index;

	node_index = 0;
	while (node_index != argc - 1)
	{
		if (last_sort_checker == 0 && (check_list_sorted(*(stack.a)) == 0
				&& check_list_reverse_sorted(*(stack.b)) == 0))
			break ;
		if (((((*(stack.a))->content) >> num_pos) & 1) == 0)
		{
			push(stack.a, stack.b);
			write(1, "pb\n", 3);
		}
		else
		{
			shift_up(stack.a);
			write(1, "ra\n", 3);
		}
		node_index++;
	}
}

void	radix(t_list **stack_a, t_list **stack_b, int argc)
{
	int				num_pos;
	int				max_num;
	struct s_stack	stack;

	stack.a = stack_a;
	stack.b = stack_b;
	max_num = argc - 1;
	num_pos = 0;
	while (max_num > 0)
	{
		sort_stack_a_radix(stack, num_pos, argc, max_num / 2);
		empty_stack_b_radix(stack_a, stack_b);
		num_pos++;
		max_num /= 2;
	}
}
