/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:45 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:53 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem;
	const unsigned char	*old;
	size_t				ctd;

	ctd = 0;
	mem = dest;
	old = src;
	while (ctd < n && (src || dest))
	{
		mem[ctd] = old[ctd];
		ctd++;
	}
	return (dest);
}
