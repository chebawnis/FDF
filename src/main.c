/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:58:41 by adichou           #+#    #+#             */
/*   Updated: 2025/02/01 05:20:52 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf(int fd, char *map)
{
	t_mlx									mlx;

	set_mlx(&mlx, fd);
	close(fd);
	fd = open(map, O_RDONLY);
	fill_tab(fd, mlx.tab, &mlx.lrg_x, &mlx.longueur_y);
	center_tab(mlx.tab, mlx.lrg_x, mlx.longueur_y);
	display_tab(&mlx);
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
