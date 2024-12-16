/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:20:48 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 17:49:01 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_gradient(t_map p1, t_map p2, int x)
{
	float	percent;
	int		red;
	int		green;
	int		blue;

	if (p1.color == p2.color)
		return (p1.color);
	if (p1.x_proj == p2.x_proj)
		return (p1.color);
	percent = (float)(x - p1.x_proj) / (p2.x_proj - p1.x_proj);
	red = (int)((p1.color >> 16) + percent * ((p2.color >> 16)
				- (p1.color >> 16)));
	green = (int)((p1.color >> 8 & 0xFF) + percent * ((p2.color >> 8 & 0xFF)
				- (p1.color >> 8 & 0xFF)));
	blue = (int)((p1.color & 0xFF) + percent * ((p2.color & 0xFF)
				- (p1.color & 0xFF)));
	return ((red << 16) | (green << 8) | blue);
}
