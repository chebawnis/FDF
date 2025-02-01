/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:27:34 by adichou           #+#    #+#             */
/*   Updated: 2025/02/01 03:33:15 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/LIBFT/libft.h"
# include "X11/X.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef RES_X
#  define RES_X 1920
# endif
# ifndef RES_Y
#  define RES_Y 1080
# endif
# ifndef MULTIPLICATEUR
#  define MULTIPLICATEUR 30
# endif
# ifndef ZMULTIPLICATEUR
#  define ZMULTIPLICATEUR 5
# endif
# ifndef MOVSPEED
#  define MOVSPEED 20
# endif
# ifndef ZOOMSPEED
#  define ZOOMSPEED 1.03
# endif
# ifndef DEZOOMSPEED
#  define DEZOOMSPEED 0.95
# endif
# ifndef ROTATESPEED
#  define ROTATESPEED 0.05
# endif
# ifndef ADDHEIGHTSPEED
#  define ADDHEIGHTSPEED 1.5
# endif
# ifndef RMHEIGHTSPEED
#  define RMHEIGHTSPEED 0.8
# endif
# ifndef BACKGROUNDCOLOR
#  define BACKGROUNDCOLOR 0xC7E5FF
# endif

typedef struct s_mlx
{
	void									*ptr;
	void									*winptr;
	void									*img;
	char									*data;
	int										bpp;
	int										sl;
	int										endian;
	float									**tab;
	int										size_tab;
	int										lrg_x;
	int										longueur_y;
	float									x_lag;
	float									y_lag;
	int										keys[256];
}	t_mlx;

int			gnl_split(int *buf_read, int fd, char buffer[], int *buf_pos);
char		*get_next_line(int fd);
int			countwords(char const *s);
size_t		count_values(int fd);
size_t		count_values(int fd);
int			fill_line(char *line, float **tab, int lineindex, int *points_lus);
void		fill_tab(int fd, float **tab, int	*longueur_x, int *largeur_y);
float		v_abs(float n);
void		rotate_x(float **tab, int size_tab);
void		rotate_y(float **tab, int size_tab);
void		rotate_z(float **tab, int size_tab);
void		r_rotate_x(float **tab, int size_tab);
void		r_rotate_y(float **tab, int size_tab);
void		r_rotate_z(float **tab, int size_tab);
void		move_tab_right(float *x_lag);
void		move_tab_left(float *x_lag);
void		move_tab_down(float *x_lag);
void		move_tab_up(float *x_lag);
void		dezoom_tab(float **tab, float size_tab);
void		zoom_tab(float **tab, float size_tab);
void		center_tab(float **tab, int lrg_x, int longueur_y);
void		drawline(t_mlx *mlx, int p0[2], int p1[2]);
void		ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void		display_lines(t_mlx *mlx);
void		display(t_mlx *mlx);
void		set_mlx(t_mlx *mlx, int fd);
int			key_hook(int keycode, t_mlx *mlx);
int			key_release_hook(int keycode, t_mlx *mlx);
int			loop_hook_bis(t_mlx *mlx);
int			loop_hook(t_mlx *mlx);
int			close_window(t_mlx *mlx);
void		display(t_mlx *mlx);
void		display_tab(t_mlx *mlx);

#endif
