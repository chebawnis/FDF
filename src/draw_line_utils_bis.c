/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:18:56 by adichou           #+#    #+#             */
/*   Updated: 2025/02/06 04:06:30 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_deltas(int d[2], int p0[3], int p1[3])
{
	d[0] = abs(p1[0] - p0[0]);
	d[1] = -abs(p1[1] - p0[1]);
}

void	init_steps(int s[2], int p0[3], int p1[3])
{
	if (p0[0] < p1[0])
		s[0] = 1;
	else
		s[0] = -1;
	if (p0[1] < p1[1])
		s[1] = 1;
	else
		s[1] = -1;
}
