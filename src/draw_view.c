/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:49:13 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 20:10:24 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	_fdf_offset_init(t_offset *offset)
{
	offset->i = 0;
	offset->j = 0;
	offset->min_x = INT_MAX;
	offset->max_x = INT_MIN;
	offset->min_y = INT_MAX;
	offset->max_y = INT_MIN;
}

void	fdf_draw_iso(t_fdf *fdf)
{
	int		i;
	int		j;
	float	scale_x;
	float	scale_y;

	i = 0;
	if ((fdf->offset_x == 0 && fdf->offset_y == 0) || fdf->view_changed)
		_fdf_calc_offset(fdf);
	while (i < fdf->line)
	{
		j = 0;
		while (j < fdf->col)
		{
			scale_x = fdf->map[i][j].x_orig * fdf->zoom;
			scale_y = fdf->map[i][j].y_orig * fdf->zoom;
			fdf->map[i][j].x_proj = (scale_x - scale_y) * cos(0.523599)
				+ fdf->offset_x;
			fdf->map[i][j].y_proj = (scale_x + scale_y) * sin(0.523599)
				- (fdf->map[i][j].z_orig * fdf->zoom) + fdf->offset_y;
			j++;
		}
		i++;
	}
}

void	fdf_draw_parallel(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	if ((fdf->offset_x == 0 && fdf->offset_y == 0) || fdf->view_changed)
		_fdf_calc_offset(fdf);
	while (i < fdf->line)
	{
		j = 0;
		while (j < fdf->col)
		{
			fdf->map[i][j].x_proj = fdf->map[i][j].x_orig * fdf->zoom
				+ fdf->offset_x;
			fdf->map[i][j].y_proj = -fdf->map[i][j].z_orig * fdf->zoom
				+ fdf->offset_y;
			j++;
		}
		i++;
	}
}

void	fdf_draw_top(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	if ((fdf->offset_x == 0 && fdf->offset_y == 0) || fdf->view_changed)
		_fdf_calc_offset(fdf);
	while (i < fdf->line)
	{
		j = 0;
		while (j < fdf->col)
		{
			fdf->map[i][j].x_proj = fdf->map[i][j].x_orig * fdf->zoom
				+ fdf->offset_x;
			fdf->map[i][j].y_proj = fdf->map[i][j].y_orig * fdf->zoom
				+ fdf->offset_y;
			j++;
		}
		i++;
	}
}
