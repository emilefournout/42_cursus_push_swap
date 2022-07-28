/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:17 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:57:31 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	execute_push_bonus(t_list **stack_a, t_list **stack_b, char instruction)
{
	if (instruction == 1)
		return (push_bonus(stack_b, stack_a));
	else if (instruction == 2)
		return (push_bonus(stack_a, stack_b));
	return (1);
}

int	execute_swap_bonus(t_list **stack_a, t_list **stack_b, char instruction)
{
	if (instruction == 3)
		return (swap_bonus(stack_a));
	else if (instruction == 4)
		return (swap_bonus(stack_b));
	else if (instruction == 5)
		return (double_swap_bonus(stack_a, stack_b));
	return (1);
}

int	execute_shift_bonus(t_list **stack_a, t_list **stack_b, char instruction)
{
	if (instruction == 6)
		return (shift_up_bonus(stack_a));
	else if (instruction == 7)
		return (shift_up_bonus(stack_b));
	else if (instruction == 8)
		return (double_shift_up_bonus(stack_a, stack_b));
	else if (instruction == 9)
		return (shift_down_bonus(stack_a));
	else if (instruction == 10)
		return (shift_down_bonus(stack_b));
	else if (instruction == 11)
		return (double_shift_down_bonus(stack_a, stack_b));
	return (1);
}
