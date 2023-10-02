/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:03 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/02 14:18:16 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function searches for the char c in the string str
//It returns a pointer to the first char in finds 

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

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char c[11] = "test string";

	printf("%s\n", (char *)strchr(c, 's'));
	printf("%s\n", (char *)ft_strchr(c, 's'));
	return (0);
} */