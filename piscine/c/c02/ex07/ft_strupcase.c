/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:41:00 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/04 21:46:25 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*original;

	original = str;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z')) 
		{
			*str = *str - 32;
		}
		str++;
	}
	return (original);
}

/*int main()
{
	char str[15] = "Teste De sTrINg";
	char *result = ft_strupcase(str);
	printf("%s\n", result); 
}*/