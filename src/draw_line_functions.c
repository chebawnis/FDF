/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:46:30 by adichou           #+#    #+#             */
/*   Updated: 2025/02/01 06:17:01 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int										pixel_index;
	if (x > 0 && y > 0 && x < RES_X && y < RES_Y)
	{
		pixel_index = (y * mlx->sl) + (x * mlx->bpp / 8);
		*(unsigned int *)(mlx->data + pixel_index) = color;	
	}
}

// void	drawline(t_mlx *mlx, int x0, int y0, int x1, int y1)
// {
// 	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
// 	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;  
// 	int err = dx+dy, e2; /* error value e_xy */

// 	for(;;)
// 	{
// 		if (x0 > 0 && y0 > 0 && x0 < RES_X && y0 < RES_Y)
// 			ft_pixel_put(mlx, x0, y0, 0xFF00FF);
// 		if (x0==x1 && y0==y1)
// 			break;
// 		e2 = 2*err;
// 		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
// 		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
// 	}
// }

void	drawline(t_mlx *mlx, int p0[2], int p1[2])
{
	int dx =  abs(p1[0] - p0[0]), sx = p0[0] < p1[0] ? 1 : -1;	
	int dy = -abs(p1[1] - p0[1]), sy = p0[1] < p1[1] ? 1 : -1;  
	int err = dx+dy, e2; /* error value e_xy */

	while (1)
	{
		ft_pixel_put(mlx, p0[0], p0[1], 0xFF00FF);
		if (p0[0]==p1[0] && p0[1]==p1[1])
			break;
		e2 = 2*err;
		if (e2 >= dy) { err += dy; p0[0] += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; p0[1] += sy; } /* e_xy+e_y < 0 */
	}
}

// void	display_lines(t_mlx *mlx)
// {
// 	int										i;
// 	int										x1;
// 	int										y1;
// 	int										x2;
// 	int										y2;

// 	i = -1;
// 	while (++i < mlx->size_tab - 1)
// 	{
// 		x1 = (int)round(mlx->tab[i][0]) + mlx->x_lag;
// 		y1 = (int)round(mlx->tab[i][1]) + mlx->y_lag;
// 		x2 = (int)round(mlx->tab[i + 1][0]) + mlx->x_lag;
// 		y2 = (int)round(mlx->tab[i + 1][1]) + mlx->y_lag;
// 		if ((i + 1) % (int)round(mlx->lrg_x) != 0)
// 			drawline(mlx, x1, y1, x2, y2);
// 	}
// 	i = (int)round(mlx->lrg_x) - 1;
// 	while (++i < mlx->size_tab)
// 	{
// 		x1 = (int)round(mlx->tab[i][0]) + mlx->x_lag;
// 		y1 = (int)round(mlx->tab[i][1]) + mlx->y_lag;
// 		x2 = (int)round(mlx->tab[i - (int)round(mlx->lrg_x)][0]) + mlx->x_lag;
// 		y2 = (int)round(mlx->tab[i - (int)round(mlx->lrg_x)][1]) + mlx->y_lag;
// 		drawline(mlx, x1, y1, x2, y2);
// 	}
// }

void	display_lines(t_mlx *mlx)
{
	int										i;
	int										p0[2];
	int										p1[2];

	i = -1;
	while (++i < mlx->size_tab - 1)
	{
		p0[0] = (int)round(mlx->tab[i][0]) + mlx->x_lag;
		p0[1] = (int)round(mlx->tab[i][1]) + mlx->y_lag;
		p1[0] = (int)round(mlx->tab[i + 1][0]) + mlx->x_lag;
		p1[1] = (int)round(mlx->tab[i + 1][1]) + mlx->y_lag;
		if ((i + 1) % (int)round(mlx->lrg_x) != 0)
			drawline(mlx, p0, p1);
	}
	i = (int)round(mlx->lrg_x) - 1;
	while (++i < mlx->size_tab)
	{
		p0[0] = (int)round(mlx->tab[i][0]) + mlx->x_lag;
		p0[1] = (int)round(mlx->tab[i][1]) + mlx->y_lag;
		p1[0] = (int)round(mlx->tab[i - (int)round(mlx->lrg_x)][0]) + mlx->x_lag;
		p1[1] = (int)round(mlx->tab[i - (int)round(mlx->lrg_x)][1]) + mlx->y_lag;
		drawline(mlx, p0, p1);
	}
}

void	display_dots(t_mlx *mlx)
{
	int										i;
	int										x;
	int										y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < mlx->size_tab)
	{
		x = (int)round(mlx->tab[i][0]) + mlx->x_lag;
		y = (int)round(mlx->tab[i][1]) + mlx->y_lag;
		ft_pixel_put(mlx, x, y, 0xFF00FF);
	}
}