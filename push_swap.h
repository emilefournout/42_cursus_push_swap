/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:42 by efournou          #+#    #+#             */
/*   Updated: 2022/08/01 16:40:35 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int					content;
	struct s_list		*next;
}						t_list;

struct					s_stack
{
	t_list				**a;
	t_list				**b;
};
int						ft_atoi(char *string, int *tab);
int						*argv_to_int(int argc, char *argv[]);
int						*number_to_weight(int *argv_to_int_tab, int argc);
t_list					*int_to_list(int argc, int *tab);

t_list					*ft_lstnew(int content);
void					ft_lstadd_back(t_list **lst, t_list *new);
t_list					*ft_lstlast(t_list *lst);

int						push(t_list **src, t_list **dst);
int						swap(t_list **lst);
int						shift_up(t_list **lst);
int						shift_down(t_list **lst);
t_list					*node_before_last(t_list *first, t_list *last);
int						double_swap(t_list **stack_a, t_list **stack_b);
int						double_shift_up(t_list **stack_a, t_list **stack_b);
int						double_shift_down(t_list **stack_a, t_list **stack_b);

void					print_instruction(char *instruction);
void					print_push(char instruction);
void					print_swap(char instruction);
void					print_shift(char instruction);

int						execute_instruction(t_list **stack_a, t_list **stack_b,
							char *instruction);

int						detect_useless_instruction(char *instruction);
int						check_list_sorted(t_list *stack_a);
void					bruteforce(t_list **stack_a, t_list **stack_b,
							int *input_stack);

void					radix(t_list **stack_a, t_list **stack_b, int argc);

void					exit_program(char *error_message, int *weight_tab,
							t_list *stack_a, t_list *stack_b);
void					free_list(t_list *list);
void					free_all(int *weight_tab, t_list *stack_a,
							t_list *stack_b);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
