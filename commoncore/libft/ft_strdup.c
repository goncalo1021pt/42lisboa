/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:06 by gfontao-          #+#    #+#             */
/*   Updated: 2024/04/13 18:34:55 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function duplicates a string and returns the duplicate

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	if (!s)
		return (NULL);
	duplicate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
