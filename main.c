/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:33 by efournou          #+#    #+#             */
/*   Updated: 2022/07/27 10:45:17 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*argv_to_int_tab;
	int		*weight_tab;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	argv_to_int_tab = argv_to_int(argc, argv);
	weight_tab = number_to_weight(argv_to_int_tab, argc);
	free(argv_to_int_tab);
	stack_a = int_to_list(argc, weight_tab);
	stack_b = NULL;
	if (check_list_sorted(stack_a) == 0)
		exit_program("\0", weight_tab, stack_a, stack_b);
	if (argc < 7)
		bruteforce(&stack_a, &stack_b, weight_tab);
	radix(&stack_a, &stack_b, argc);
	exit_program("\0", weight_tab, stack_a, stack_b);
}
