/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:18:53 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 17:29:26 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	_fdf_calc_offset(t_fdf *fdf)
{
	if (fdf->view == 0)
		_fdf_calc_offset_iso(fdf);
	else if (fdf->view == 1)
		_fdf_calc_offset_parallel(fdf);
	else if (fdf->view == 2)
		_fdf_calc_offset_top(fdf);
}

t_point	_fdf_calculate_iso(t_fdf *fdf, int i, int j)
{
	t_point	point;
	float	scaled_x;
	float	scaled_y;
	float	scaled_z;

	scaled_x = fdf->map[i][j].x_orig * fdf->zoom;
	scaled_y = fdf->map[i][j].y_orig * fdf->zoom;
	scaled_z = fdf->map[i][j].z_orig * fdf->zoom;
	point.draw_x = (scaled_x - scaled_y) * cos(0.523599);
	point.draw_y = -scaled_z + (scaled_x + scaled_y) * sin(0.523599);
	point.draw_z = scaled_z;
	point.color = fdf->map[i][j].color;
	return (point);
}

void	_fdf_calc_offset_iso(t_fdf *fdf)
{
	t_offset	of;
	t_point		point;

	_fdf_offset_init(&of);
	while (of.i < fdf->line)
	{
		of.j = 0;
		while (of.j < fdf->col)
		{
			point = _fdf_calculate_iso(fdf, of.i, of.j);
			if (point.draw_x < of.min_x)
				of.min_x = point.draw_x;
			if (point.draw_x > of.max_x)
				of.max_x = point.draw_x;
			if (point.draw_y < of.min_y)
				of.min_y = point.draw_y;
			if (point.draw_y > of.max_y)
				of.max_y = point.draw_y;
			of.j++;
		}
		of.i++;
	}
	fdf->offset_x = (WIDTH - (of.max_x - of.min_x)) / 2 - of.min_x;
	fdf->offset_y = (HEIGHT - (of.max_y - of.min_y)) / 2 - of.min_y;
}

void	_fdf_calc_offset_parallel(t_fdf *fdf)
{
	t_offset	of;
	t_point		point;

	_fdf_offset_init(&of);
	while (of.i < fdf->line)
	{
		of.j = 0;
		while (of.j < fdf->col)
		{
			point.draw_x = fdf->map[of.i][of.j].x_orig * fdf->zoom;
			point.draw_y = fdf->map[of.i][of.j].z_orig * fdf->zoom;
			if (point.draw_x < of.min_x)
				of.min_x = point.draw_x;
			if (point.draw_x > of.max_x)
				of.max_x = point.draw_x;
			if (point.draw_y < of.min_y)
				of.min_y = point.draw_y;
			if (point.draw_y > of.max_y)
				of.max_y = point.draw_y;
			of.j++;
		}
		of.i++;
	}
	fdf->offset_x = (WIDTH - (of.max_x - of.min_x)) / 2 - of.min_x;
	fdf->offset_y = (HEIGHT - (of.max_y - of.min_y)) / 2 - of.min_y;
}

void	_fdf_calc_offset_top(t_fdf *fdf)
{
	t_offset	of;
	t_point		point;

	_fdf_offset_init(&of);
	while (of.i < fdf->line)
	{
		of.j = 0;
		while (of.j < fdf->col)
		{
			point.draw_x = fdf->map[of.i][of.j].x_orig * fdf->zoom;
			point.draw_y = fdf->map[of.i][of.j].y_orig * fdf->zoom;
			if (point.draw_x < of.min_x)
				of.min_x = point.draw_x;
			if (point.draw_x > of.max_x)
				of.max_x = point.draw_x;
			if (point.draw_y < of.min_y)
				of.min_y = point.draw_y;
			if (point.draw_y > of.max_y)
				of.max_y = point.draw_y;
			of.j++;
		}
		of.i++;
	}
	fdf->offset_x = (WIDTH - (of.max_x - of.min_x)) / 2 - of.min_x;
	fdf->offset_y = (HEIGHT - (of.max_y - of.min_y)) / 2 - of.min_y;
}
