/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:00:01 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 17:47:51 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_init(t_fdf *fdf, char *file)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->zoom = 1.0;
	fdf->img = malloc(sizeof(t_img));
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	count_array(file, &fdf);
	fdf->view = 0;
	fdf->view_changed = 1;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
}

static	void	init_map(t_fdf **fdf)
{
	int		i;

	(*fdf)->map = malloc(sizeof(t_map *) * (*fdf)->line);
	if (!(*fdf)->map)
	{
		ft_printf("Error: failed to allocate memory\n");
		exit(1);
	}
	i = 0;
	while (i < (*fdf)->line)
	{
		(*fdf)->map[i] = malloc(sizeof(t_map) * (*fdf)->col);
		if (!(*fdf)->map[i])
		{
			ft_printf("Error: failed to allocate memory\n");
			exit(1);
		}
		i++;
	}
}

static	void	parse_line(t_fdf *fdf, char **split, int j)
{
	int		i;
	char	**split2;

	i = 0;
	while (i < fdf->col)
	{
		split2 = ft_split(split[i], ',');
		fdf->map[j][i].x_orig = i * 20;
		fdf->map[j][i].y_orig = j * 20;
		fdf->map[j][i].z_orig = ft_atoi(split2[0]);
		if (split2[1])
			fdf->map[j][i].color = ft_atoi_base(split2[1] + 2,
					"0123456789ABCDEF");
		else
			fdf->map[j][i].color = 0xFFFFFF;
		i++;
		free_split(split2);
	}
}

void	fdf_read_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		j;

	init_map(&fdf);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: failed to open file\n");
		exit(1);
	}
	line = get_next_line(fd);
	j = 0;
	while (j < fdf->line)
	{
		split = ft_split(line, ' ');
		parse_line(fdf, split, j);
		free(line);
		free_split(split);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	close(fd);
}
