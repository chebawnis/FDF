/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:41:25 by adichou           #+#    #+#             */
/*   Updated: 2025/01/28 01:12:05 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_tab_right(float *x_lag)
{
	*x_lag += MOVSPEED;
}

void	move_tab_left(float *x_lag)
{
	*x_lag -= MOVSPEED;
}

void	move_tab_down(float *y_lag)
{
	*y_lag += MOVSPEED;
}

void	move_tab_up(float *y_lag)
{
	*y_lag -= MOVSPEED;
}

void	center_tab(float (*tab)[3], float largeur_x, float longueur_y)
{
	int										i;
	int										nline;
	float									half_x;
	float									half_y;

	i = 0;
	half_x = (largeur_x * MULTIPLICATEUR) / 2;
	half_y = (longueur_y * MULTIPLICATEUR) / 2;
	nline = largeur_x * longueur_y;
	while (i < nline)
	{
		tab[i][0] -= half_x;
		tab[i][1] -= half_y;
		i ++;
	}
}
