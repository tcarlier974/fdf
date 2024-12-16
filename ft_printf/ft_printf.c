/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:42:56 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/15 17:36:35 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	in_charset(char c)
{
	int		i;
	char	*charset;

	charset = "cspdiuxX%";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	rout(va_list arg, const char *fmt, int *i, int *j)
{
	if (fmt[*i + 1] == 'c' && fmt[*i + 1])
		*j += printc((char)va_arg(arg, int));
	if (fmt[*i + 1] == 's' && fmt[*i + 1])
		*j += prints((char *)va_arg(arg, char *));
	if (fmt[*i + 1] == 'p' && fmt[*i + 1])
		*j += printp((unsigned long long)va_arg(arg, unsigned long long));
	if (fmt[*i + 1] == 'd' && fmt[*i + 1])
		*j += printd((long)va_arg(arg, long));
	if (fmt[*i + 1] == 'i' && fmt[*i + 1])
		*j += printd((int)va_arg(arg, int));
	if (fmt[*i + 1] == 'u' && fmt[*i + 1])
		*j += printu((unsigned int)va_arg(arg, unsigned int));
	if (fmt[*i + 1] == 'x' && fmt[*i + 1])
		*j += printx((unsigned int)va_arg(arg, unsigned int));
	if (fmt[*i + 1] == 'X' && fmt[*i + 1])
		*j += print_x((unsigned int)va_arg(arg, unsigned int));
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	arg;
	int		j;

	va_start(arg, fmt);
	i = 0;
	j = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && in_charset(fmt[i + 1]))
		{
			if (fmt[i + 1] == '%')
				j += printc('%');
			else
				rout(arg, fmt, &i, &j);
			i += 2;
			continue ;
		}
		printc(fmt[i]);
		i++;
		j++;
	}
	return (j);
}

/*#include <stdio.h>
int main(void)
{
	printf("Le vrai : %i\n", -44);
	ft_printf("Le faux : %d\n", -44);
	return (0);
}*/
