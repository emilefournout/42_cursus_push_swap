/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:09:55 by efournou          #+#    #+#             */
/*   Updated: 2022/07/29 12:36:40 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *string, int *tab)
{
	int				index;
	long long int	number;

	number = 0;
	index = 0;
	if (string[0] == '-')
		index++;
	while (string[index] != '\0')
	{
		number *= 10;
		if (string[index] < 48 || string[index] > 57)
			exit_program("Error\n", tab, NULL, NULL);
		number += string[index] - '0';
		index++;
	}
	if (string[0] == '-' && index == 1)
		exit_program("Error\n", tab, NULL, NULL);
	if (string[0] == '-')
		number = -number;
	if (number > 2147483647 || number < -2147483648)
		exit_program("Error\n", tab, NULL, NULL);
	return (((int)number));
}

void	check_double_number(int *tab, int number, int tab_index)
{
	int	index;

	index = 0;
	while (index != tab_index)
	{
		if (tab[index] == number)
		{			
			exit_program("Error\n", tab, NULL, NULL);
		}
		index++;
	}
}

int	*argv_to_int(int argc, char *argv[])
{
	int	*return_tab;
	int	index;
	int	number;

	index = 0;
	return_tab = (int *)malloc((argc - 1) * sizeof(int));
	if (return_tab == (void *)0)
		exit_program("Error\n", return_tab, NULL, NULL);
	while (argv[index + 1] != NULL)
	{
		number = ft_atoi(argv[index + 1], return_tab);
		check_double_number(return_tab, number, index);
		return_tab[index] = number;
		index++;
	}
	return (return_tab);
}

t_list	*int_to_list(int argc, int *tab)
{
	int		index;
	t_list	*first_node;
	t_list	*lst;

	index = 0;
	first_node = ft_lstnew(tab[0]);
	lst = first_node;
	index++;
	while (index != argc - 1)
	{
		lst->next = ft_lstnew(tab[index]);
		lst = lst->next;
		index++;
	}
	return (first_node);
}
