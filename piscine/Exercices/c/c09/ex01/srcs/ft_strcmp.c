/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:22:56 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/15 12:12:38 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	ctd;

	ctd = 0;
	while (s1[ctd] == s2[ctd] && (s1[ctd] != '\0' && s2[ctd] != '\0'))
	{
		ctd++;
	}
	return (s1[ctd] - s2[ctd]);
}
