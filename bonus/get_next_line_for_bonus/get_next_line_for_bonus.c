/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_for_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:30:12 by efournou          #+#    #+#             */
/*   Updated: 2022/07/26 16:32:24 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_for_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

int	ft_strchr(const char *s, int c, int end)
{
	int	i;

	i = 0;
	while (i != end)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_line(int fd, char **return_string)
{
	int			result;
	static char	buffer[BUFFER_SIZE];
	int			char_pos;

	result = -2;
	if (**return_string == '\0')
		*return_string = ft_strjoin_nfree(*return_string, buffer);
	char_pos = ft_strchr(buffer, 10, BUFFER_SIZE);
	if (char_pos == -1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
			return (-1);
		*return_string = ft_strjoin_nfree(*return_string, buffer);
		if (result != 0)
			return (check_line(fd, return_string));
	}
	if (BUFFER_SIZE != 1 && char_pos + 1 != BUFFER_SIZE)
		ft_strlcpy(&buffer[0], &buffer[char_pos + 1], BUFFER_SIZE - char_pos
			- 1);
	else
		ft_bzero(buffer, BUFFER_SIZE);
	return (result);
}

char	*get_next_line(int fd)
{
	char	*return_string;
	int		result;

	return_string = (char *)malloc(sizeof(char));
	if (!return_string)
	{
		free(return_string);
		return (NULL);
	}
	*return_string = '\0';
	result = check_line(fd, &return_string);
	if (result == -1 || (result == 0 && *return_string == '\0'))
	{
		free(return_string);
		return (NULL);
	}
	return (return_string);
}
/*
#include <stdio.h>
int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i != 12)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}
*/
