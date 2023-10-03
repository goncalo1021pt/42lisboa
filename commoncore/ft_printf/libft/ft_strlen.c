/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 14:02:20 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// this functions returns the lenght of the string str

size_t	ft_strlen(const char *str)
{
	size_t	ctd;

	ctd = 0;
	while (str[ctd])
		ctd++;
	return (ctd);
}
