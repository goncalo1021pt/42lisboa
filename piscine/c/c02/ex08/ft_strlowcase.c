/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:52:28 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/04 22:11:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char	*str)
{
	char	*original;

	original = str;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Z')) 
		{
			*str = *str + 32;
		}
		str++;
	}
	return (original);
}

/*int main() {
    char str[15] = "Teste De sTrINg";
    char *result = ft_strlowcase(str);
    printf("%s\n", result);
}*/
