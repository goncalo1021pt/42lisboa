/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:24:42 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/06 22:45:50 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*od;
	int		ctd;

	ctd = 0;
	od = dest;
	dest += ft_strlen(dest);
	while (ctd < ft_strlen(src) && (unsigned int)ctd < nb)
	{
		*dest = src[ctd];
		dest++;
		ctd++;
	}
	*dest = '\0';
	return (od);
}

/*int main()
{
    char dest[50] = "Testing ";
    char src[] = "ola";

    ft_strncat(dest, src,9);
    printf("%s\n", dest);
    return 0;
}*/