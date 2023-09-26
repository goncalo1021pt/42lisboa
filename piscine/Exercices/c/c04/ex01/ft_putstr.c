/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:12:05 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/07 14:47:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
	{
		write(1, &str[ctd], 1);
		ctd++;
	}
}

/*int	main(void)
{
	char c[5]= "teste";
	ft_putstr(c);
}*/