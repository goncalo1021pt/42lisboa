/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:49 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:51 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	ctd;

	ctd = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{
		ctd = (int)n - 1;
		while (ctd >= 0 && ctd < (int)n)
		{
			(((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd]);
			ctd--;
		}
	}
	else
	{
		while (ctd < (int)n)
		{
			(((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd]);
			ctd++;
		}
	}
	return (dest);
}
