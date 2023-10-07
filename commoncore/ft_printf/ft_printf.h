/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:20:14 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/06 19:58:06 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define EX_LOW_BASE "0123456789abcdef"
# define EX_UP_BASE "0123456789ABCDEF"
# define POSSIBLE_FLAGS "cspdiuxX%"

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned int nbr, char *base, int total);
int	ft_putpt(unsigned long int nbr, char *base, int total);
int	ft_putnbr(int n, int total);
int	ft_putunbr(unsigned int n, int total);

#endif