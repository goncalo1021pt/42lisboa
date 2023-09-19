/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:21:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/06 22:45:59 by gfontao-         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	char	*od;
	int		ctd;

	ctd = 0;
	od = dest;
	dest += ft_strlen(dest);
	while (ctd < ft_strlen(src))
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
    char src[] = "my string";

    //ft_strcat(dest, src);
    printf("%s\n", ft_strcat(dest,src));
    return 0;
}*/