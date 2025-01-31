/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:58:41 by adichou           #+#    #+#             */
/*   Updated: 2025/01/31 22:28:42 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	add_height(float **tab, float size_tab, float r_x, float r_y, float r_z)
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

// void	rm_height(float **tab, float size_tab, float r_x, float r_y, float r_z)
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

int close_window(t_mlx *mlx)
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

int key_hook(int keycode, t_mlx *mlx)
{
    if (keycode == 65307)
        close_window(mlx);
	else if (keycode == 105)
	{
		rotate_x(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 111)
	{
		rotate_y(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 112)
	{
		rotate_z(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 107)
	{
		r_rotate_x(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 108)
	{
		r_rotate_y(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 59)
	{
		r_rotate_z(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 113)
	{
		zoom_tab(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 101)
	{
		dezoom_tab(mlx->tab, mlx->size_tab);
		display(mlx);
	}
	else if (keycode == 119)
	{
		mlx->y_lag -= MOVSPEED;
		display(mlx);
	}
	else if (keycode == 115)
	{
		mlx->y_lag += MOVSPEED;
		display(mlx);
	}
	else if (keycode == 97)
	{
		mlx->x_lag -= MOVSPEED;
		display(mlx);
	}
	else if (keycode == 100)
	{
		mlx->x_lag += MOVSPEED;
		display(mlx);
	}
	
    return (0);
}

void	ft_clear_img(t_mlx *mlx)
{
	int										*buff;
	int										total;
	int										i;
	
	buff = (int *)mlx->data;
	total = RESOLUTION_X * RESOLUTION_Y;
	i = -1;
	while (++ i < total)
		buff[i] = BACKGROUNDCOLOR;
}


void	display(t_mlx *mlx)
{
	ft_clear_img(mlx);
	display_lines(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->winptr, mlx->img, 0, 0);
}

void	display_tab(t_mlx *mlx)
{
	int										i;

	i = 0;
	while (i < 3)
	{
		zoom_tab(mlx->tab, mlx->size_tab);
		rotate_x(mlx->tab, mlx->size_tab);
		rotate_y(mlx->tab, mlx->size_tab);
		rotate_z(mlx->tab, mlx->size_tab);
		i ++;
	}
	
		
	mlx->ptr = mlx_init();
	mlx->winptr = mlx_new_window(mlx->ptr, RESOLUTION_X, RESOLUTION_Y, "FENETRE");
	mlx->img = NULL;
	mlx->img = mlx_new_image(mlx->ptr, RESOLUTION_X, RESOLUTION_Y);
	if (!mlx->img)
		return ;
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel, &mlx->size_line, &mlx->endian);




	
	display(mlx);
	

	mlx_key_hook(mlx->winptr, key_hook, mlx);
	mlx_hook(mlx->winptr, 17, 0, close_window, mlx);
	

	mlx_loop(mlx->ptr);
}

void	fdf(int	fd, char *map)
{
	t_mlx									mlx;
	int i = 0;

	mlx.x_lag = RESOLUTION_X / 2;
	mlx.y_lag = RESOLUTION_Y / 2;
	mlx.size_tab = count_values(fd);
	printf("SIZE TAB = %d\n\n", mlx.size_tab);
	mlx.tab = malloc(mlx.size_tab * sizeof(float *));
	while (i < mlx.size_tab)
	{
		mlx.tab[i] = malloc(3 * sizeof(float));
		if (!mlx.tab[i])
		{
			printf("l'allocation de tab[%d] a échoué\n", i);
			while (--i >= 0)
				free(mlx.tab[i]);
			free(mlx.tab);
			return;
		}
		i ++;
	}
	close(fd);
	fd = open(map, O_RDONLY);
	fill_tab(fd, mlx.tab, &mlx.largeur_x, &mlx.longueur_y);
	center_tab(mlx.tab, mlx.largeur_x, mlx.longueur_y);
	display_tab(&mlx);

	i = 0;
	for (i = 1; i < mlx.size_tab + 1; i++)
		printf("point %d,\nX = %f,\nY = %f,\nZ = %f\n\n", i, mlx.tab[i][0], mlx.tab[i][1], mlx.tab[i][2]);

	
}

int	main(int argc, char **argv)
{
	int										fd;
	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		fdf(fd, argv[1]);
		close(fd);
	}
	else
		printf("met la map en argument tmr\n");
	
	return (0);
}






