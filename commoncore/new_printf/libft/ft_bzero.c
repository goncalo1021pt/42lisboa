/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:08 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 14:01:09 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function will set n number of bytes of the string str to \0 character

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*mem;
	size_t			ctd;

	ctd = 0;
	mem = str;
	while (ctd < n)
		mem[ctd++] = '\0';
}

/* #include <stdio.h>
int main(){
	char test[] = "testing string";
	
	printf("before function: %s\n", test);
	ft_bzero (test, 14);
	printf("after function: %s\n", test);
} */