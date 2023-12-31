/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:45 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/30 19:49:18 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This functions copies n bytes from src into dest
//It doesn't take care of overlaping memory
//It returns a pointer to n the start of dest

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
