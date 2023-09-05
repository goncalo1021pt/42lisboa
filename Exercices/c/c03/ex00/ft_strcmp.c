/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/05 16:10:26 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	a = s1[i];
	b = s2[i];
	return (a - b);
}

int main(void)
{
	char str1[] = "testing string 1";
	char str2[] = "testing string 0";

	int result = ft_strcmp(str1, str2);

	printf("result = %d",result);
}