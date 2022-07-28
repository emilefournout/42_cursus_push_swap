/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:46 by efournou          #+#    #+#             */
/*   Updated: 2022/07/16 20:32:03 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_list **src, t_list **dst)
{
	t_list	*src_list;

	src_list = *src;
	if (src_list == NULL)
		return (1);
	*src = src_list->next;
	src_list->next = *dst;
	*dst = src_list;
	return (0);
}
