/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_for_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:31:09 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 16:32:35 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_for_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(dst);
	while (*dst)
		dst++;
	while (i < dstsize - size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		if (src[i - 1] == '\n')
			break ;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_nfree(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;

	size = 0;
	dst = (void *) '\0';
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + BUFFER_SIZE;
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (dst == (void *) '\0')
		return ((void *) '\0');
	dst[0] = '\0';
	ft_strlcat(dst, s1, size + 1);
	free((char *)s1);
	ft_strlcat(dst, s2, size + 1);
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	counter;

	counter = 0;
	while (counter != dstsize)
	{
		dst[counter] = src[counter];
		counter++;
	}
	while (counter != BUFFER_SIZE)
	{
		dst[counter] = '\0';
		counter++;
	}
	return (dstsize);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		size;

	dst = (void *) '\0';
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst = (char *)malloc(1);
		if (!dst)
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	if (ft_strlen(&(s[start])) < len)
		size = ft_strlen(&(s[start]));
	else
		size = len;
	dst = (char *)malloc(size + 1);
	if (dst == (void *) '\0')
		return ((void *) '\0');
	ft_strlcpy(dst, &(s[start]), size + 1);
	return (dst);
}
