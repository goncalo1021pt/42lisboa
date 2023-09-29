/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:54 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/29 14:15:48 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		ctd;
	char	*str;

	str = (char *)malloc(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[ctd])
	{
		str[ctd] = f(ctd, s[ctd]);
		ctd++;
	}
	return (str);
}
