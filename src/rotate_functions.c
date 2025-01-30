/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:45:20 by adichou           #+#    #+#             */
/*   Updated: 2025/01/22 20:39:44 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_x(float (*tab)[3], float size_tab, float *r)
{
	int										i;
	float 									x;
	float 									z;
	
	i = 0;
	while (i < size_tab)
	{
		x = (tab[i][0] * cos(ROTATESPEED)) - (tab[i][1] * sin(ROTATESPEED));
		z = (tab[i][0] * sin(ROTATESPEED)) + (tab[i][1] * cos(ROTATESPEED));
		tab[i][0] = x;
		tab[i][1] = z;
		i ++;
	}
	(*r) += 1;
}

void	rotate_y(float (*tab)[3], float size_tab, float *r)
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
	(*r) += 1;
}

void	rotate_z(float (*tab)[3], float size_tab, float *r)
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
	(*r) += 1;
}