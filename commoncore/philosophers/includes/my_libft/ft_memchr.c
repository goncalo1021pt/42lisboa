/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:56 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				ctd;
	unsigned char		*s;

	ctd = 0;
	s = (unsigned char *)str;
	while (ctd < n)
	{
		if (s[ctd] == (unsigned char)c)
			return ((void *)s + ctd);
		ctd++;
	}
	return (NULL);
}
