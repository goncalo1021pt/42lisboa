/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:53:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/06 11:23:57 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str && str[ctd] && str[ctd] != '\n')
		ctd++;
	return (ctd);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ctd;
	size_t	ctd2;
	char	*str;

	ctd = 0;
	str = (char *)malloc(ft_linelen(s1) + ft_linelen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[ctd])
	{
		str[ctd] = s1[ctd];
		ctd++;
	}
	ctd2 = 0;
	while (s2[ctd2] != '\n' && s2[ctd2])
	{
		str[ctd + ctd2] = s2[ctd2];
		ctd2++;
	}
	if (s2[ctd2] == '\n')
		str[ctd2] = '\n';
	if (s1)
		free(s1);
	return (str);
}

void	buffer_clean(char *str)
{
	int	ctd;

	ctd = 0;
	while (ctd < BUFFER_SIZE)
	{
		str[ctd] = 0;
		ctd++;
	}
}
