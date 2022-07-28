/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:01:04 by efournou          #+#    #+#             */
/*   Updated: 2022/07/19 05:05:08 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while (s1[counter] != '\0' && s2[counter] != '\0'
		&& s1[counter] == s2[counter] && counter < n - 1)
		counter++;
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
