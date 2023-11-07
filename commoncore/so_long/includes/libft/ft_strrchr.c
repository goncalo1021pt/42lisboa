/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:30 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ctd;
	char	*str;

	str = (char *)s;
	ctd = 0;
	while (str[ctd])
		ctd++;
	while (ctd >= 0)
	{
		if (s[ctd] == (char)c)
			return (str + ctd);
		ctd--;
	}
	return (NULL);
}
