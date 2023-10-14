/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:03 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:46 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		ctd;
	char	*str;

	str = (char *)s;
	ctd = 0;
	while (s[ctd])
	{
		if (s[ctd] == (char)c)
			return (str + ctd);
		ctd++;
	}
	if (str[ctd] == '\0' && (char)c == '\0')
		return (str + ctd);
	return (NULL);
}
