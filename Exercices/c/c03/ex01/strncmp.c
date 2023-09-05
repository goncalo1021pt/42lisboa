/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:10:07 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/05 16:13:57 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') && i + 1 < n)
	{
		i++;
	}
	a = s1[i];
	b = s2[i];
	return (a - b);
}

int main(void)
{
	char str1[] = "test string 1";
	char str2[] = "test string 2";
	

	int result = ft_strncmp(str1, str2, 13);
	printf("result = %d",result);

}