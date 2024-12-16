/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:19:02 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/15 17:40:43 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	len_nb(int n)
{
	long int	i;
	int			count;

	count = 0;
	i = n;
	if (n < 0)
	{
		count++;
		i = -i;
	}
	while (i > 9)
	{
		i = i / 10;
		count++;
	}
	return (count + 1);
}

int	printd(int nb)
{
	char	*res;
	int		nblen;

	nblen = len_nb(nb);
	res = ft_itoa(nb);
	prints(res);
	free(res);
	return (nblen);
}
