/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:24:54 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/19 17:06:45 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_map
{
	int		x_orig;
	int		y_orig;
	int		z_orig;
	int		x_proj;
	int		y_proj;
	int		color;
}	t_map;

typedef struct s_offset
{
	int		i;
	int		j;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
}				t_offset;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		**map;
	t_img		*img;
	float		zoom;
	int			col;
	int			line;
	int			offset_x;
	int			offset_y;
	int			view;
	int			view_changed;
}	t_fdf;

typedef struct s_point
{
	int		origin_x;
	int		origin_y;
	int		origin_z;
	int		draw_x;
	int		draw_y;
	int		draw_z;
	int		color;
}	t_point;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		err;
	int		e2;
	int		x;
	int		y;
	int		sx;
	int		sy;
}	t_bresenham;

void	fdf_init(t_fdf *fdf, char *file);
void	_fdf_calc_offset(t_fdf *fdf);
void	fdf_read_map(t_fdf *fdf, char *file);
void	fdf_draw(t_fdf *fdf, int view);
int		handle_hook(int keycode, t_fdf *fdf);
void	count_array(char *file, t_fdf **fdf);
void	fdf_free_map(t_fdf *fdf);
void	fdf_draw_lines(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_map p1, t_map p2);
void	init_bresenham(t_bresenham *bres, t_map p1, t_map p2);
int		create_gradient(t_map p1, t_map p2, int x);
int		fdf_exit(t_fdf *fdf);
void	fdf_draw_iso(t_fdf *fdf);
void	fdf_draw_parallel(t_fdf *fdf);
void	fdf_draw_top(t_fdf *fdf);
void	free_split(char **split);
int		ft_atoi_base(char *str, char *base);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	_fdf_calc_offset_iso(t_fdf *fdf);
void	_fdf_calc_offset_parallel(t_fdf *fdf);
void	_fdf_calc_offset_top(t_fdf *fdf);
void	_fdf_offset_init(t_offset *of);
t_point	_fdf_calculate_iso(t_fdf *fdf, int i, int j);

#endif