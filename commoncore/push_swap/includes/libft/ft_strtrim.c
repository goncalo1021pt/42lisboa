/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:42 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:32 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(const char *str, const char c)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
	{
		if (str[ctd] == c)
			return (1);
		ctd++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	ctd;
	char	*str;

	start = 0;
	ctd = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && is_char(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_char(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	while (start < end)
	{
		str[ctd] = s1[start];
		ctd++;
		start++;
	}
	str[ctd] = '\0';
	return (str);
}

/* #include <stdio.h>
int	main(void)
{
	char *test;

	test = ft_strtrim("12345abc123456", "1234567890");
	printf("%s\n", test);
	free(test);
} */