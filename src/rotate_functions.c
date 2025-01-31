/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:45:20 by adichou           #+#    #+#             */
/*   Updated: 2025/01/31 05:33:32 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_x(float **tab, int size_tab)
{
	int										i;
	float 									x;
	float 									z;
	
	i = 0;
	while (i < size_tab)
	{
		if (tab[i] == NULL)
		{
			printf("\n\nErreur: tab[%d] est NULL dans rotate_x\n\n\n", i);
			exit(1);
		}
		x = (tab[i][0] * cos(ROTATESPEED)) - (tab[i][1] * sin(ROTATESPEED));
		z = (tab[i][0] * sin(ROTATESPEED)) + (tab[i][1] * cos(ROTATESPEED));
		tab[i][0] = x;
		tab[i][1] = z;
		i ++;
	}
	// (*r) += 1;
}

void	rotate_y(float **tab, int size_tab)
{
	int										i;
	float 									x;
	float 									z;
	
	i = 0;
	while (i < size_tab)
	{
		x = (tab[i][0] * cos(ROTATESPEED)) - (tab[i][2] * sin(ROTATESPEED));
		z = (tab[i][0] * sin(ROTATESPEED)) + (tab[i][2] * cos(ROTATESPEED));
		tab[i][0] = x;
		tab[i][2] = z;
		i ++;
	}
	// (*r) += 1;
}

void	rotate_z(float **tab, int size_tab)
{
	int										i;
	float 									x;
	float 									z;
	
	i = 0;
	while (i < size_tab)
	{
		x = (tab[i][1] * cos(ROTATESPEED * 2)) - (tab[i][2] * sin(ROTATESPEED * 2));
		z = (tab[i][1] * sin(ROTATESPEED * 2)) + (tab[i][2] * cos(ROTATESPEED * 2));
		tab[i][1] = x;
		tab[i][2] = z;
		i ++;
	}
	// (*r) += 1;
}