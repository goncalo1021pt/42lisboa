/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/03 21:40:43 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int flag_type(char c, va_list *args)
{
	int len;

	len = 0;
	if (c == 'c')
		ft_putchar_fd((va_arg(*args, int)), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	if (c == 'p')
		va_arg(*args, unsigned long);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*args, int),1);
	if (c == 'u')
		ft_putunbr_fd(va_arg(*args, unsigned int), 1, 0);
	if (c == 'x')
		va_arg(*args, unsigned int);
	if (c == 'X')
		va_arg(*args, unsigned int);
	if (c == '%')
		write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	len;
	int ctd;
	va_list args;

	ctd = 0;
	va_start(args, str);
	while (str[ctd])
	{
		if(str[ctd++] == '%')
			flag_type(str, &args);
		else
			write(1, &str[ctd], 1);
		ctd++;
	}
	va_end(args);
	return (len);
}	
