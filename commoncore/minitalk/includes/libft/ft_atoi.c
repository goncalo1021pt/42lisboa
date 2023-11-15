/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:04 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/10 23:51:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ctd;
	int	signal;
	int	result;

	ctd = 0;
	signal = 1;
	result = 0;
	while (nptr[ctd] == ' ' || (nptr[ctd] >= 9 && nptr[ctd] <= 13))
		ctd++;
	if (nptr[ctd] == '+' || nptr[ctd] == '-')
		if (nptr[ctd++] == '-')
			signal = -signal;
	while (nptr[ctd] <= '9' && nptr[ctd] >= '0')
	{
		result *= 10;
		result += nptr[ctd++] - '0';
	}
	return (signal * result);
}
