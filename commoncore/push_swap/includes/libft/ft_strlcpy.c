/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:15 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:21:07 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctd;
	size_t	src_len;

	ctd = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	if (sizeof(dest != 0))
	{
		while (ctd < size - 1 && src[ctd])
		{
			dest[ctd] = src[ctd];
			ctd++;
		}
		dest[ctd] = '\0';
	}
	return (src_len);
}
