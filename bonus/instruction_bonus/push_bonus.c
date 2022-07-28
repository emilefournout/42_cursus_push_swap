/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:46 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 14:59:31 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	push_bonus(t_list **src, t_list **dst)
{
	t_list	*src_list;

	src_list = *src;
	if (src_list == NULL)
		return (0);
	*src = src_list->next;
	src_list->next = *dst;
	*dst = src_list;
	return (0);
}
