/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:36 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 17:58:31 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	nblen_16(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*int_to_base_16(unsigned int n)
{
	long	nb;
	char	*dst;
	int		i;

	nb = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	dst = (char *)malloc(sizeof(char) * (nblen_16(nb) + 1));
	if (!dst)
		return (NULL);
	i = nblen_16(nb) - 1;
	while (nb > 0)
	{
		if (nb % 16 < 10)
			dst[i--] = (nb % 16) + 48;
		else
			dst[i--] = (nb % 16) + 87;
		nb /= 16;
	}
	dst[nblen_16(n)] = '\0';
	return (dst);
}

int	printx(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	str = int_to_base_16(n);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	len = prints(str);
	free(str);
	return (len);
}

int	print_x(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	str = int_to_base_16(n);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	len = prints(str);
	free(str);
	return (len);
}
