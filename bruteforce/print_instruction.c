/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:38 by efournou          #+#    #+#             */
/*   Updated: 2022/07/19 00:40:57 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_push(char instruction)
{
	if (instruction == 1)
		write(1, "pa\n", 3);
	else if (instruction == 2)
		write(1, "pb\n", 3);
}

void	print_swap(char instruction)
{
	if (instruction == 3)
		write(1, "sa\n", 3);
	else if (instruction == 4)
		write(1, "sb\n", 3);
	else if (instruction == 5)
		write(1, "ss\n", 3);
}

void	print_shift(char instruction)
{
	if (instruction == 6)
		write(1, "ra\n", 3);
	else if (instruction == 7)
		write(1, "rb\n", 3);
	else if (instruction == 8)
		write(1, "rr\n", 3);
	else if (instruction == 9)
		write(1, "rra\n", 4);
	else if (instruction == 10)
		write(1, "rrb\n", 4);
	else if (instruction == 11)
		write(1, "rrr\n", 4);
}

void	print_instruction(char *instruction)
{
	int	index;

	index = 0;
	while (instruction[index] != '\0')
	{
		if (instruction[index] == 1 || instruction[index] == 2)
			print_push(instruction[index]);
		else if (instruction[index] >= 3 && instruction[index] <= 5)
			print_swap(instruction[index]);
		else
			print_shift(instruction[index]);
		index++;
	}
}
