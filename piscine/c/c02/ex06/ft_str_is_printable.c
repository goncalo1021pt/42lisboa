/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:28:25 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/04 21:38:23 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str > 31 && *str < 127))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int	main(void)
{
	char c[20];

	printf("\n%d", ft_str_is_printable("teste"));
}*/