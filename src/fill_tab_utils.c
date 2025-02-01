/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:54:00 by adichou           #+#    #+#             */
/*   Updated: 2025/02/01 03:15:29 by adichou          ###   ########.fr       */
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
			break ;
		count += countwords(line);
		free (line);
	}
	return (count);
}

int	fill_line(char *line, float **tab, int line_i, int *pts_i)
{
	int										i;
	int										j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		tab[*pts_i][0] = j * MULTIPLICATEUR;
		tab[*pts_i][1] = line_i * MULTIPLICATEUR;
		tab[*pts_i][2] = ft_atoi(line + i) * ZMULTIPLICATEUR;
		(*pts_i)++;
		while (line[i] != ' ' && line[i] != '\0')
			i ++;
		j ++;
	}
	return (0);
}

void	fill_tab(int fd, float **tab, int	*largeur_x, int *longueur_y)
{
	int										points_lus;
	int										lineindex;
	char									*line;

	points_lus = 0;
	lineindex = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		*largeur_x = countwords(line);
		fill_line(line, tab, lineindex, &points_lus);
		lineindex ++;
		free (line);
	}
	*longueur_y = lineindex;
}
