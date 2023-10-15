/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:59:22 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 10:20:59 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_len(long int n)
{
	long int	aux;
	long int	size;

	aux = n;
	size = 1;
	if (n < 0)
	{
		size++;
		aux = -aux;
	}
	while (aux / 10 > 0)
	{
		aux /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	n1;
	int			size;
	char		*str;

	n1 = n;
	size = total_len(n1);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (n1 < 0)
	{
		str[0] = '-';
		n1 = -n1;
	}
	if (n1 == 0)
		str[0] = '0';
	str[size] = '\0';
	size--;
	while (size >= 0 && n1 > 0)
	{
		str[size] = (n1 % 10) + '0';
		n1 /= 10;
		size--;
	}
	return (str);
}
