/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:31:05 by adichou           #+#    #+#             */
/*   Updated: 2025/02/01 03:16:37 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_mlx(t_mlx *mlx, int fd)
{
	int										i;

	i = 0;
	mlx->x_lag = RES_X / 2;
	mlx->y_lag = RES_Y / 2;
	mlx->size_tab = count_values(fd);
	ft_memset(mlx->keys, 0, sizeof(mlx->keys));
	mlx->tab = malloc(mlx->size_tab * sizeof(float *));
	while (i < mlx->size_tab)
	{
		mlx->tab[i] = malloc(3 * sizeof(float));
		if (!mlx->tab[i])
		{
			while (--i >= 0)
				free(mlx->tab[i]);
			free(mlx->tab);
			return ;
		}
		i ++;
	}
}

int	close_window(t_mlx *mlx)
{
	int										i;

	i = 0;
	while (i < mlx->size_tab)
	{
		free(mlx->tab[i]);
		i ++;
	}
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->winptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	free(mlx->tab);
	exit(0);
	return (0);
}

void	display(t_mlx *mlx)
{
	int										*buff;
	int										total;
	int										i;

	buff = (int *)mlx->data;
	total = RES_X * RES_Y;
	i = -1;
	while (++ i < total)
		buff[i] = BACKGROUNDCOLOR;
	display_lines(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->winptr, mlx->img, 0, 0);
}

void	display_tab(t_mlx *mlx)
{
	int										i;

	i = 0;
	while (i < 5)
	{
		zoom_tab(mlx->tab, mlx->size_tab);
		rotate_x(mlx->tab, mlx->size_tab);
		rotate_y(mlx->tab, mlx->size_tab);
		rotate_z(mlx->tab, mlx->size_tab);
		i ++;
	}
	mlx->ptr = mlx_init();
	mlx->winptr = mlx_new_window(mlx->ptr, RES_X, RES_Y, "FENETRE");
	mlx->img = NULL;
	mlx->img = mlx_new_image(mlx->ptr, RES_X, RES_Y);
	if (!mlx->img)
		return ;
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian);
	display(mlx);
	mlx_hook(mlx->winptr, 17, 0, close_window, mlx);
	mlx_hook(mlx->winptr, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->winptr, 3, (1L << 1), key_release_hook, mlx);
	mlx_loop_hook(mlx->ptr, loop_hook, mlx);
	mlx_loop(mlx->ptr);
}
