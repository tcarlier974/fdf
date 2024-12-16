/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:51:16 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 18:18:30 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_draw(t_fdf *fdf, int view)
{
	if (view == 0)
		fdf_draw_iso(fdf);
	else if (view == 1)
		fdf_draw_parallel(fdf);
	else if (view == 2)
		fdf_draw_top(fdf);
	fdf_draw_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void	fdf_draw_lines(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->line)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (j < fdf->col - 1)
				draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
			if (i < fdf->line - 1)
				draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	draw_line(t_fdf *fdf, t_map p1, t_map p2)
{
	t_bresenham	bres;
	t_map		xtmp;

	init_bresenham(&bres, p1, p2);
	xtmp = p1;
	while (1)
	{
		my_mlx_pixel_put(fdf, p1.x_proj, p1.y_proj,
			create_gradient(xtmp, p2, p1.x_proj));
		if (p1.x_proj == p2.x_proj && p1.y_proj == p2.y_proj)
			break ;
		bres.e2 = bres.err * 2;
		if (bres.e2 >= -bres.dy)
		{
			bres.err -= bres.dy;
			p1.x_proj += bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err += bres.dx;
			p1.y_proj += bres.sy;
		}
	}
}
