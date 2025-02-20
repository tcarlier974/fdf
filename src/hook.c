/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:49:50 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:47 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_exit(t_fdf *fdf)
{
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img && fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->map)
	{
		while (fdf->line)
			free(fdf->map[--fdf->line]);
		free(fdf->map);
	}
	if (fdf->img)
		free(fdf->img);
	if (fdf->mlx)
		free(fdf->mlx);
	exit(0);
}

static	void	handle_offset(int keycode, t_fdf *fdf)
{
	if (keycode == 115)
		fdf->offset_y += 10;
	else if (keycode == 119)
		fdf->offset_y -= 10;
	else if (keycode == 97)
		fdf->offset_x += 10;
	else if (keycode == 100)
		fdf->offset_x -= 10;
}

static	void	handle_keycode(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		fdf_exit(fdf);
	else if (keycode == 65364)
		fdf->zoom *= 0.9;
	else if (keycode == 65362)
		fdf->zoom *= 1.1;
	if (keycode == 115 || keycode == 100 || keycode == 97 || keycode == 119)
	{
		handle_offset(keycode, fdf);
		fdf->view_changed = 0;
	}
	if (keycode == 116)
		fdf->view = 2;
	if (keycode == 112)
		fdf->view = 1;
	if (keycode == 105)
		fdf->view = 0;
}

int	handle_hook(int keycode, t_fdf *fdf)
{
	fdf->view_changed = 1;
	handle_keycode(keycode, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bits_per_pixel, &fdf->img->line_length,
			&fdf->img->endian);
	fdf_draw(fdf, fdf->view);
	return (0);
}
