/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:04:59 by efournou          #+#    #+#             */
/*   Updated: 2022/08/01 16:40:20 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	detect_command(char *instruction)
{
	if (ft_strncmp(instruction, "pa\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		return (2);
	else if (ft_strncmp(instruction, "sa\n", 4) == 0)
		return (3);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		return (4);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
		return (5);
	else if (ft_strncmp(instruction, "ra\n", 4) == 0)
		return (6);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		return (7);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		return (8);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		return (9);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		return (10);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		return (11);
	return (-1);
}

int	execute_single_instruction(t_list **stack_a, t_list **stack_b,
		char instruction)
{
	int	return_value;

	return_value = 1;
	if (instruction == 1 || instruction == 2)
		return_value = execute_push_bonus(stack_a, stack_b, instruction);
	else if (instruction >= 3 && instruction <= 5)
		return_value = execute_swap_bonus(stack_a, stack_b, instruction);
	else
		return_value = execute_shift_bonus(stack_a, stack_b, instruction);
	if (return_value != 0)
		return (1);
	return (0);
}

int	apply_stdin_instruction(t_list **stack_a, t_list **stack_b)
{
	char	instruction_number;
	char	*instruction_from_stdin;

	instruction_from_stdin = get_next_line(0);
	while (instruction_from_stdin != (void *)0)
	{
		instruction_number = detect_command(instruction_from_stdin);
		if (instruction_number == -1)
			return (1);
		if (execute_single_instruction(stack_a, stack_b,
				instruction_number) == 1)
			return (1);
		free(instruction_from_stdin);
		instruction_from_stdin = get_next_line(0);
	}
	return (0);
}
