/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:12:25 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/15 17:51:11 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	nb_len16(unsigned long long n)
{
	int			count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char	*int_to_hexa(unsigned long long n)
{
	char				*str;
	int					i;
	unsigned long long	n_t;

	n_t = n;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((nb_len16(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = nb_len16(n) - 1;
	while (n > 0)
	{
		if (n % 16 < 10)
			str[i--] = (n % 16) + 48;
		else
			str[i--] = (n % 16) + 87;
		n = n / 16;
	}
	str[nb_len16(n_t)] = '\0';
	return (str);
}

int	printp(unsigned long long nb)
{
	char	*str;
	int		len;

	if (!nb)
		return (prints("(nil)"));
	str = int_to_hexa(nb);
	len = 0;
	if (str && ft_strlen(str) > 0)
		len += prints("0x");
	len += prints(str);
	free(str);
	return (len);
}
