/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:06 by gfontao-          #+#    #+#             */
/*   Updated: 2024/10/27 11:56:28 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function duplicates a string and returns the duplicate

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
