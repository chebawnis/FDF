/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:27:34 by adichou           #+#    #+#             */
/*   Updated: 2025/01/30 00:17:38 by adichou          ###   ########.fr       */
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
# ifndef RESOLUTION_X
#  define RESOLUTION_X 1920
# endif
# ifndef RESOLUTION_Y
#  define RESOLUTION_Y 1080
# endif
# ifndef MULTIPLICATEUR
#  define MULTIPLICATEUR 10
# endif
# ifndef MOVSPEED
#  define MOVSPEED 1
# endif
# ifndef ZOOMSPEED
#  define ZOOMSPEED 1.5
# endif
# ifndef DEZOOMSPEED
#  define DEZOOMSPEED 0.75
# endif
# ifndef ROTATESPEED
#  define ROTATESPEED 0.001
# endif
# ifndef ADDHEIGHTSPEED
#  define ADDHEIGHTSPEED 1.5
# endif
# ifndef RMHEIGHTSPEED
#  define RMHEIGHTSPEED 0.8
# endif

int							gnl_split(int *buf_read, int fd, char buffer[], int *buf_pos);
char						*get_next_line(int fd);
int							countwords(char const *s);
size_t						count_values(int fd);
void						*ft_realloc(void *ptr, size_t oldsize, size_t newsize);
size_t						count_values(int fd);
int							fill_line(char *line, float (*tab)[3], int lineindex, int *points_lus, size_t oldsize);
void						fill_tab(int fd, float (*tab)[3], float	*longueur_x, float *largeur_y);
float						v_abs(float n);
void						rotate_x(float (*tab)[3], float size_tab, float *r);
void						rotate_y(float (*tab)[3], float size_tab, float *r);
void						rotate_z(float (*tab)[3], float size_tab, float *r);
void						r_rotate_x(float (*tab)[3], float size_tab, float *r);
void						r_rotate_y(float (*tab)[3], float size_tab, float *r);
void						r_rotate_z(float (*tab)[3], float size_tab, float *r);
void						move_tab_right(float *x_lag);
void						move_tab_left(float *x_lag);
void						move_tab_down(float *x_lag);
void						move_tab_up(float *x_lag);
void						dezoom_tab(float (*tab)[3], float size_tab);
void						zoom_tab(float (*tab)[3], float size_tab);
void						align_x(float (*tab)[3], float size_tab, float r);
void						align_y(float (*tab)[3], float size_tab, float r);
void						align_z(float (*tab)[3], float size_tab, float r);
void						put_back_x(float (*tab)[3], float size_tab, float r);
void						put_back_y(float (*tab)[3], float size_tab, float r);
void						put_back_z(float (*tab)[3], float size_tab, float r);
void						center_tab(float (*tab)[3], float largeur_x, float longueur_y);



#endif
