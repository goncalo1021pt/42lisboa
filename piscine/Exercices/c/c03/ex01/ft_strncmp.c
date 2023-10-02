/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:07:45 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/29 15:21:06 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (0);
	while (s1[c] == s2[c] && (s1[c] && s2[c]) && c < n - 1)
	{
		c++;
	}
	return (s1[c] - s2[c]);
}

/*int main(void)
{
char str1[7] = "teste1";
char str2[7] = "teste2";

printf ("\n%d\n", ft_strncmp(str1, str2,6));
return 0;
}*/