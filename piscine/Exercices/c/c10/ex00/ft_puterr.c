/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:02 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/20 11:05:05 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puterr(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
	{
		write(2, &str[ctd], 1);
		ctd++;
	}
}
