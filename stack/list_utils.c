/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:28 by efournou          #+#    #+#             */
/*   Updated: 2022/07/19 05:05:40 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return ((void *) '\0');
	new_element->content = content;
	new_element->next = (void *) '\0';
	return (new_element);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == (void *)0)
		return ((void *)0);
	while (lst->next != (void *)0)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst == (void *)0)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}
