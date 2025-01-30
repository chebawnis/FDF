/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:58:41 by adichou           #+#    #+#             */
/*   Updated: 2025/01/30 02:39:57 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef struct s_mlx
{
	void									*ptr;
	void									*winptr;
	void									*img;
	char									*data;
	int										bit_per_pixel;
	int										size_line;
	int										endian;
} t_mlx;


// void	add_height(float (*tab)[3], float size_tab, float r_x, float r_y, float r_z)
// {
// 	int										i;
// 	i = 0;
// 	align_x(tab, size_tab, r_x);
// 	align_y(tab, size_tab, r_y);
// 	align_z(tab, size_tab, r_z);
// 	while (i ++ < size_tab)
// 		tab[i][2] *= ADDHEIGHTSPEED;
// 	put_back_x(tab, size_tab, r_x);
// 	put_back_y(tab, size_tab, r_y);
// 	put_back_z(tab, size_tab, r_z);
// }

// void	rm_height(float (*tab)[3], float size_tab, float r_x, float r_y, float r_z)
// {
// 	int										i;
// 	i = 0;
// 	align_x(tab, size_tab, r_x);
// 	align_y(tab, size_tab, r_y);
// 	align_z(tab, size_tab, r_z);
// 	while (i ++ < size_tab)
// 		tab[i][2] *= RMHEIGHTSPEED;
// 	put_back_x(tab, size_tab, r_x);
// 	put_back_y(tab, size_tab, r_y);
// 	put_back_z(tab, size_tab, r_z);
// }

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int										pixel_index;

	pixel_index = (y * mlx->size_line) + (x * mlx->bit_per_pixel / 8);
	*(unsigned int *)(mlx->data + pixel_index) = color;
}

void	drawline(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;  
	int err = dx+dy, e2; /* error value e_xy */

	for(;;)
	{
		ft_pixel_put(mlx, x0, y0, 0xFF00FF);
		if (x0==x1 && y0==y1)
			break;
		e2 = 2*err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

void	connect_lines(t_mlx *mlx, float (*tab)[3], float largeur_x, float size_tab)
{
	int										i;
	int										x1;
	int										y1;
	int										x2;
	int										y2;

	i = -1;
	while (i ++ < size_tab - 1)
	{
		x1 = (int)round(tab[i][0]) + RESOLUTION_X / 2;
		y1 = (int)round(tab[i][1]) + RESOLUTION_Y / 2;
		x2 = (int)round(tab[i + 1][0]) + RESOLUTION_X / 2;
		y2 = (int)round(tab[i + 1][1]) + RESOLUTION_Y / 2;
		if ((i + 1) % (int)round(largeur_x) != 0)
			drawline(mlx, x1, y1, x2, y2);
	}
	i = (int)round(largeur_x) - 1;
	while (i ++ < size_tab - 1)
	{
		x1 = (int)round(tab[i][0]) + RESOLUTION_X / 2;
		y1 = (int)round(tab[i][1]) + RESOLUTION_Y / 2;
		x2 = (int)round(tab[i - (int)round(largeur_x)][0]) + RESOLUTION_X / 2;
		y2 = (int)round(tab[i - (int)round(largeur_x)][1]) + RESOLUTION_Y / 2;
		drawline(mlx, x1, y1, x2, y2);
	}
}

void	display(t_mlx *mlx, float (*tab)[3], float largeur_x, float size_tab)
{
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->ptr, RESOLUTION_X, RESOLUTION_Y);
	if (!mlx->img)
		return ;
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel, &mlx->size_line, &mlx->endian);
	connect_lines(mlx, tab, largeur_x, size_tab);
	mlx_put_image_to_window(mlx->ptr, mlx->winptr, mlx->img, 0, 0);
}

void	display_tab(float (*tab)[3], float largeur_x, float longueur_y)
{
	t_mlx									mlx;
	int										i;
	float									size_tab;
	float									x_lag;
	float									y_lag;
	float									r_x;
	float									r_y;
	float									r_z;
	
	i = 0;
	size_tab = largeur_x * longueur_y;

	x_lag = RESOLUTION_X / 2;
	y_lag = RESOLUTION_Y / 2;

	r_x = 0;
	r_y = 0;
	r_z = 0;

	mlx.ptr = mlx_init();
	mlx.winptr = mlx_new_window(mlx.ptr, RESOLUTION_X, RESOLUTION_Y, "FENETRE");


	zoom_tab(tab, size_tab);
	zoom_tab(tab, size_tab);
	zoom_tab(tab, size_tab);
	mlx.img = NULL;
	while (i < 100)
	{
		rotate_x(tab, size_tab, &r_x);
		rotate_y(tab, size_tab, &r_y);
		rotate_z(tab, size_tab, &r_z);
		display(&mlx, tab, largeur_x, size_tab); //6 ERREURS??
		i ++;
	}
	mlx_destroy_image(mlx.ptr, mlx.img);
	exit(0);
	
	//mlx_loop(mlx.ptr);
}

void	fdf(int	fd, char *map)
{
	float									**tab;
	float									largeur_x;
	float									longueur_y;

	tab = malloc(count_values(fd) * sizeof(float *));
	close(fd);
	fd = open(map, O_RDONLY);
	fill_tab(fd, tab, &largeur_x, &longueur_y);
	// center_tab(tab, largeur_x, longueur_y);
	// display_tab(tab, largeur_x, longueur_y);
	int i = 0;
	while (i < longueur_y)
		free(tab[i++]);
	free(tab);
	
}

int	main(int argc, char **argv)
{
	int										fd;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		fdf(fd, argv[1]);
		close(fd);
	}
	else
		printf("met la map en argument tmr\n");
	
	return (0);
}
