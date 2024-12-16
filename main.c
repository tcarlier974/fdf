/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:24:21 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 18:17:40 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
	{
		ft_printf("Usage: ./fdf [map]\n");
		return (1);
	}
	fdf_init(&fdf, av[1]);
	fdf_read_map(&fdf, av[1]);
	fdf_draw(&fdf, 0);
	mlx_hook(fdf.win, 17, 1L << 17, ft_exit, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
