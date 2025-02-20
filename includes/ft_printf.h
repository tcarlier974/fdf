/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:43:24 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/12 23:58:27 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);
int		printc(char c);
int		prints(char	*str);
int		printd(int nb);
void	rout(va_list ap, const char *fmt, int *i, int *len);
int		printu(unsigned int n);
int		printx(unsigned int nb);
int		print_x(unsigned int nb);
int		printp(unsigned long long nb);
char	*int_to_hexa(unsigned long long n);
int		nb_len16(unsigned long long n);

#endif
