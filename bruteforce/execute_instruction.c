/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:17 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:49:27 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	execute_push(t_list **stack_a, t_list **stack_b,
		char instruction)
{
	if (instruction == 1)
		return (push(stack_b, stack_a));
	else if (instruction == 2)
		return (push(stack_a, stack_b));
	return (1);
}

static int	execute_swap(t_list **stack_a, t_list **stack_b,
		char instruction)
{
	if (instruction == 3)
		return (swap(stack_a));
	else if (instruction == 4)
		return (swap(stack_b));
	else if (instruction == 5)
		return (double_swap(stack_a, stack_b));
	return (1);
}

static int	execute_shift(t_list **stack_a, t_list **stack_b,
		char instruction)
{
	if (instruction == 6)
		return (shift_up(stack_a));
	else if (instruction == 7)
		return (shift_up(stack_b));
	else if (instruction == 8)
		return (double_shift_up(stack_a, stack_b));
	else if (instruction == 9)
		return (shift_down(stack_a));
	else if (instruction == 10)
		return (shift_down(stack_b));
	else if (instruction == 11)
		return (double_shift_down(stack_a, stack_b));
	return (1);
}

int	execute_instruction(t_list **stack_a, t_list **stack_b, char *instruction)
{
	int	index;
	int	return_value;

	index = 0;
	return_value = 1;
	while (instruction[index] != '\0')
	{
		if (instruction[index] == 1 || instruction[index] == 2)
			return_value = execute_push(stack_a, stack_b, instruction[index]);
		else if (instruction[index] >= 3 && instruction[index] <= 5)
			return_value = execute_swap(stack_a, stack_b, instruction[index]);
		else
			return_value = execute_shift(stack_a, stack_b, instruction[index]);
		if (return_value != 0)
			return (1);
		index++;
	}
	return (0);
}
