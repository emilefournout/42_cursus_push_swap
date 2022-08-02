/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:05:10 by efournou          #+#    #+#             */
/*   Updated: 2022/08/01 16:34:37 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	checker(int argc, char *argv[])
{
	int			*argv_to_int_tab;
	int			*weight_tab;
	t_list		*stack_a;
	t_list		*stack_b;

	argv_to_int_tab = argv_to_int(argc, argv);
	weight_tab = number_to_weight(argv_to_int_tab, argc);
	stack_a = int_to_list(argc, argv_to_int_tab);
	free(argv_to_int_tab);
	stack_b = NULL;
	if (apply_stdin_instruction(&stack_a, &stack_b) == 1)
		exit_program("Error\n", weight_tab, stack_a, stack_b);
	if (check_list_sorted_bonus(stack_a, stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_program("\0", weight_tab, stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		exit (0);
	checker(argc, argv);
}
