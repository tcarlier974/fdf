/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:42:57 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 18:18:05 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

void	count_array(char *file, t_fdf **fdf)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: failed to open file\n");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	(*fdf)->line = count_lines(fd);
	(*fdf)->col = i;
	free(line);
	free_split(split);
	close(fd);
}
