/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_weight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:34:03 by efournou          #+#    #+#             */
/*   Updated: 2022/07/29 12:38:56 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_malloc(int *new_weight_tab, int *argv_to_int_tab)
{
	if (new_weight_tab == (void *)0)
	{
		free(argv_to_int_tab);
		exit_program("Error\n", new_weight_tab, NULL, NULL);
	}
}

int	*number_to_weight(int *argv_to_int_tab, int argc)
{
	int	index;
	int	tempo_index;
	int	weight;
	int	weight_index;
	int	*new_weight_tab;

	new_weight_tab = (int *)malloc((argc - 1) * sizeof(int));
	check_malloc(new_weight_tab, argv_to_int_tab);
	index = 0;
	weight_index = 0;
	while (index != argc - 1)
	{
		weight = 1;
		tempo_index = 0;
		while (tempo_index != argc - 1)
		{
			if (argv_to_int_tab[tempo_index] < argv_to_int_tab[weight_index])
				weight++;
			tempo_index++;
		}
		new_weight_tab[weight_index] = weight;
		weight_index++;
		index++;
	}
	return (new_weight_tab);
}
