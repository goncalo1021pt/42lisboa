/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:49:23 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:21:06 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ctd;
	unsigned int	sstr;
	unsigned int	sdest;

	ctd = 0;
	sdest = ft_strlen(dest);
	sstr = ft_strlen(src);
	if (size < 1)
		return (sstr + size);
	while (src[ctd] && (ctd + sdest) < size -1)
	{
		dest[ctd + sdest] = src[ctd];
		ctd++;
	}
	dest[ctd + sdest] = '\0';
	if (size < sdest)
		return (sstr + size);
	else
		return (sdest + sstr);
}
