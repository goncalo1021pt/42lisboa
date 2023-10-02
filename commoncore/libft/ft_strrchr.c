/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 14:02:38 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function searches for the char c in the string str
//It returns a pointer to the last char in finds 

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

/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char c[11] = "hello world";
	char *test;

	test = ft_strrchr(c, 's');
	if (test == 0)
		printf("NULL");
	else
		printf("%s\n", test);
	return (0);
} */