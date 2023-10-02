/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/02 12:45:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	ctd;
	char			*out;

	if (start >= ft_strlen(s))
		len = 0;
	else if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ctd = 0;
	while (ctd < len && len != 0)
	{
		out[ctd] = s[start + ctd];
		ctd++;
	}
	out[ctd] = '\0';
	return (out);
}

/* #include <stdio.h>
int main()
{
	char *test;

	test = ft_substr("test string", 5, 10);
	printf("%s\n", test);
	free(test);
	return (0);
} */