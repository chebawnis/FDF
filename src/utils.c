/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:39:49 by adichou           #+#    #+#             */
/*   Updated: 2025/01/22 19:43:36 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	gnl_split(int *buf_read, int fd, char buffer[], int *buf_pos)
{
	*buf_read = read(fd, buffer, 5);
	if (*buf_read == -1)
		return (0);
	*buf_pos = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[5];
	static int		buf_read;
	static int		buf_pos;
	int				i;
	char			line[50000];

	i = 0;
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			if (gnl_split(&buf_read, fd, &buffer[0], &buf_pos) == 0)
				return (NULL);
			if (buf_read == 0)
				break ;
		}
		line[i++] = buffer[buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	countwords(char const *s)
{
	int								i;
	int								count;
	char							c;

	i = 0;
	count = 0;
	c = ' ';
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr || oldsize == 0)
		return (malloc(newsize));
	void									*newmem;
	size_t									size_to_copy;
	
	newmem = malloc(newsize);
	if (!newmem)
		return (NULL);
	if (oldsize < newsize)
		size_to_copy = oldsize;
	else
		size_to_copy = newsize;
	ft_memmove(newmem, ptr, size_to_copy);
	free(ptr);
	return (newmem);
}

float	v_abs(float n)
{
	if (n > 0)
		return (n);
	return (n * -1);
}