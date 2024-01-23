/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_is_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:33:57 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/03 12:37:01 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_string_is_digit(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
	{
		if (str[ctd] < '0' || str[ctd] > '9')
			return (false);
		ctd++;
	}
	return (true);
}
