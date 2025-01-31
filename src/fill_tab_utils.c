/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:54:00 by adichou           #+#    #+#             */
/*   Updated: 2025/01/31 06:09:39 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	count_values(int fd)
{
	char									*line;
	size_t									count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		count += countwords(line);
		free (line);
	}
	return(count);
}

int	fill_line(char *line, float **tab, int lineindex, int *points_lus, size_t oldsize)
{
	int										i;
	int										j;

	i = 0;
	j = 0;
	oldsize += 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		tab[*points_lus][0] = j * MULTIPLICATEUR;
		tab[*points_lus][1] = lineindex * MULTIPLICATEUR;
		tab[*points_lus][2] = ft_atoi(line + i) * ZMULTIPLICATEUR;
		(*points_lus) ++;
		while (line[i] != ' ' && line[i] != '\0')
			i ++;
		j ++;
	}
	return (0);
}

void	fill_tab(int fd, float **tab, int	*largeur_x, int *longueur_y)
{
	size_t									oldsize;
	int										points_lus;
	int										lineindex;
	char									*line;

	oldsize = 0;
	points_lus = 0;
	lineindex = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		*largeur_x = countwords(line);
		printf("line %d ; %s\n", lineindex + 1, line);
		fill_line(line, tab, lineindex, &points_lus, oldsize);
		lineindex ++;
		free (line);
	}
	*longueur_y = lineindex;
}
