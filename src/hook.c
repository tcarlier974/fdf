/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:49:50 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/15 20:29:09 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_exit(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->line)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	free(fdf->img);
	exit(0);
	return (0);
}

static	void	handle_offset(int keycode, t_fdf *fdf)
{
	if (keycode == 126)
		fdf->offset_y += 10;
	else if (keycode == 125)
		fdf->offset_y -= 10;
	else if (keycode == 123)
		fdf->offset_x += 10;
	else if (keycode == 124)
		fdf->offset_x -= 10;
}

static	void	handle_keycode(int keycode, t_fdf *fdf)
{
	if (keycode == 52)
		ft_exit(fdf);
	else if (keycode == 1)
		fdf->zoom *= 0.9;
	else if (keycode == 12)
		fdf->zoom *= 1.1;
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		handle_offset(keycode, fdf);
		fdf->view_changed = 0;
	}
	if (keycode == 17)
		fdf->view = 2;
	if (keycode == 35)
		fdf->view = 1;
	if (keycode == 34)
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
