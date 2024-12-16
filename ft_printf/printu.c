/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:15 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/15 18:27:21 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_u_nb(long n)
{
	long	i;
	int		count;

	count = 0;
	i = n;
	if (n == 0)
		return (1);
	while (i > 9)
	{
		i = i / 10;
		count++;
	}
	return (count + 1);
}

char	*ft_u_itoa(unsigned int n)
{
	long	nb;
	char	*dst;
	int		i;

	nb = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	dst = (char *)malloc(sizeof(char) * (count_u_nb(nb) + 1));
	if (!dst)
		return (NULL);
	i = count_u_nb(nb) - 1;
	while (nb > 0)
	{
		dst[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	dst[count_u_nb(n)] = '\0';
	return (dst);
}

int	printu(unsigned int n)
{
	int		len;
	char	*res;
	long	nb;

	nb = (long)n;
	res = ft_u_itoa(nb);
	len = prints(res);
	free(res);
	return (len);
}
