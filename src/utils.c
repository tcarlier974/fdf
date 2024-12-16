/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:39:56 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 17:50:17 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->line)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
}

void	init_bresenham(t_bresenham *bres, t_map p1, t_map p2)
{
	bres->dx = abs(p2.x_proj - p1.x_proj);
	bres->dy = abs(p2.y_proj - p1.y_proj);
	bres->err = bres->dx - bres->dy;
	bres->x = p1.x_proj;
	bres->y = p1.y_proj;
	if (p1.x_proj < p2.x_proj)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (p1.y_proj < p2.y_proj)
		bres->sy = 1;
	else
		bres->sy = -1;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = fdf->img->addr + (y * fdf->img->line_length + x
			* (fdf->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
