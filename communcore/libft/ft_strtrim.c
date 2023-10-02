/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:42 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/02 18:28:05 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function eleminates character in set at the start and end of a string s1
//It returns a new string without those caracters

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
	size_t	len;
	size_t	ctd;
	char	*str;

	start = 0;
	ctd = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(set) == 0)
		return (NULL);
	if (ft_strlen(set))
	{
		while (s1[start] && is_char(set, s1[start]))
			start++;
		len = ft_strlen(s1);
		end = len - 1;
	}
	while (end > start && is_char(set, s1[end]))
		end--;
	str = (char *)malloc(len - start + (end - len));
	if (str == NULL)
		return (NULL);
	while (start <= end)
	{
		str[ctd] = s1[start];
		ctd++;
		start++;
	}
	str[start] = '\0';
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char *test;

	test = ft_strtrim("    ", "");
	printf("%s\n", test);
	free(test);
}