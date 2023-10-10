/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/10 12:40:02 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	flag_type(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd((va_arg(*args, int)), 1);
	if (c == 's')
		len += straux(va_arg(*args, char *));
	if (c == 'p')
		len += ptraux(va_arg(*args, long));
	if (c == 'd' || c == 'i')
		len += int_aux(va_arg(*args, int));
	if (c == 'u')
		len += ft_put_any_base(va_arg(*args, unsigned int), DEC_BASE, 0);
	if (c == 'x')
		len += ft_put_any_base(va_arg(*args, long), EX_LOW_BASE, 0);
	if (c == 'X')
		len += ft_put_any_base(va_arg(*args, long), EX_UP_BASE, 0);
	if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		ctd;
	va_list	args;

	if(!str)
		return(-1);
	ctd = 0;
	len = 0;
	va_start(args, str);
	while (str[ctd])
	{
		if (str[ctd] == '%' && is_char(POSSIBLE_FLAGS, str[ctd + 1]))
		{
			ctd++;
			len += flag_type(str[ctd], &args);
		}
		else
			len += write(1, &str[ctd], 1);
		ctd++;
	}
	va_end(args);
	return (len);
}
