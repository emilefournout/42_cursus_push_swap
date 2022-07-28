/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:09:37 by efournou          #+#    #+#             */
/*   Updated: 2022/07/19 20:18:04 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_list_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static void	reload_stack(t_list **stack_a, t_list **stack_b, int *input_stack)
{
	int		index;
	t_list	*list_stack_a;

	index = 0;
	while ((*stack_b) != NULL)
		push(stack_b, stack_a);
	list_stack_a = *stack_a;
	while (list_stack_a != NULL)
	{
		list_stack_a->content = input_stack[index];
		index++;
		list_stack_a = list_stack_a->next;
	}
}

static void	apply_instruction(char *instruction, t_list **stack_a,
		t_list **stack_b, int *input_stack)
{
	if (detect_useless_instruction(instruction) == 0)
	{
		if (execute_instruction(stack_a, stack_b, instruction) == 0)
		{
			if (!check_list_sorted(*stack_a))
			{
				print_instruction(instruction);
				free(instruction);
				exit_program("\0", input_stack, *stack_a, *stack_b);
			}
		}
		reload_stack(stack_a, stack_b, input_stack);
	}
}

void	bruteforce(t_list **stack_a, t_list **stack_b, int *input_stack)
{
	char			*instruction;
	int				index;
	long long int	number_possibility;
	int				index_2;

	index_2 = 0;
	number_possibility = 0;
	instruction = (char *)calloc(8, sizeof(char));
	index = 0;
	while (number_possibility != 5710169)
	{
		while (instruction[index] == 11)
		{
			instruction[index] = 1;
			index++;
		}
		instruction[index]++;
		index = 0;
		apply_instruction(instruction, stack_a, stack_b, input_stack);
		index_2 = 0;
		number_possibility++;
	}
	free(instruction);
}
