/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:52:31 by adichou           #+#    #+#             */
/*   Updated: 2025/01/30 00:54:32 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	align_x(float (*tab)[3], float size_tab, float r)
{
	int										i;

	i = 0;
	if (r > 0)
	{
		while (i < r)
		{
			r_rotate_x(tab, size_tab, 0);
			i ++;
		}
	}
	else
	{
		while (i > r)
		{
			rotate_x(tab, size_tab, 0);
			i --;
		}
	}	
}

void	align_y(float (*tab)[3], float size_tab, float r)
{
	int										i;

	i = 0;
	if (r > 0)
	{
		while (i < r)
		{
			r_rotate_y(tab, size_tab, 0);
			i ++;
		}
	}
	else
	{
		while (i > r)
		{
			rotate_y(tab, size_tab, 0);
			i --;
		}
	}	
}

void	align_z(float (*tab)[3], float size_tab, float r)
{
	int										i;

	i = 0;
	if (r > 0)
	{
		while (i < r)
		{
			r_rotate_z(tab, size_tab, 0);
			i ++;
		}
	}
	else
	{
		while (i > r)
		{
			rotate_z(tab, size_tab, 0);
			i --;
		}
	}	
}