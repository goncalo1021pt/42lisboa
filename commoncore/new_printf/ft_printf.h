/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:20:14 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 12:21:16 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define EX_LOW_BASE "0123456789abcdef"
# define EX_UP_BASE "0123456789ABCDEF"
# define DEC_BASE "0123456789"
# define POSSIBLE_FLAGS "cspdiuxX%"

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_put_any_base(unsigned long int nbr, char *base, int total);
int int_aux(long int nbr);
int	is_char(const char *str, const char c);
int	ptraux(unsigned long int ptr);
int	straux(char *str);

#endif