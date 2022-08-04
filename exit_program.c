/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:21 by efournou          #+#    #+#             */
/*   Updated: 2022/08/01 16:40:42 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_list	*next_saver;

	while (list)
	{
		next_saver = list->next;
		free(list);
		list = next_saver;
	}
}

void	free_all(int *weight_tab, t_list *stack_a, t_list *stack_b)
{
	if (weight_tab != (void *) 0)
		free(weight_tab);
	if (stack_a != (void *) 0)
		free_list(stack_a);
	if (stack_b != (void *) 0)
		free_list(stack_b);
}

static void	print_string_on_stderr(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		write(2, &string[index], 1);
		index++;
	}
}

void	exit_program(char *error_message, int *weight_tab, t_list *stack_a,
		t_list *stack_b)
{
	free_all(weight_tab, stack_a, stack_b);
	if (error_message[0] == '\0')
		exit(0);
	print_string_on_stderr(error_message);
	exit(1);
}
