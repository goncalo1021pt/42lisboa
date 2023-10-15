/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:54 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/30 21:14:22 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		ctd;
	char	*str;

	ctd = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[ctd])
	{
		str[ctd] = f(ctd, s[ctd]);
		ctd++;
	}
	str[ctd] = '\0';
	return (str);
}
