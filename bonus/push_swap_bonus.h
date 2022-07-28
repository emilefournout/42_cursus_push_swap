/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:05:12 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 16:30:05 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"
# include "get_next_line_for_bonus/get_next_line_for_bonus.h"

char		detect_command(char *instruction);
int			execute_single_instruction(t_list **stack_a, t_list **stack_b,
				char instruction);
t_list_char	*ft_lstchar_new(char content);
int			apply_stdin_instruction(t_list **stack_a, t_list **stack_b,
				t_list_char *instruction);
void		print_list_instruction(t_list_char *instruction);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			execute_push_bonus(t_list **stack_a, t_list **stack_b,
				char instruction);
int			execute_swap_bonus(t_list **stack_a, t_list **stack_b,
				char instruction);
int			execute_shift_bonus(t_list **stack_a, t_list **stack_b,
				char instruction);

int			push_bonus(t_list **src, t_list **dst);
int			double_shift_down_bonus(t_list **stack_a, t_list **stack_b);
int			shift_down_bonus(t_list **lst);
int			double_shift_up_bonus(t_list **stack_a, t_list **stack_b);
int			shift_up_bonus(t_list **lst);
int			double_swap_bonus(t_list **stack_a, t_list **stack_b);
int			swap_bonus(t_list **lst);

int			check_list_sorted_bonus(t_list *stack_a, t_list *stack_b);

#endif
