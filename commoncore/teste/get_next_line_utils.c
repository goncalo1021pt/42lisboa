/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:38:42 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/07 13:23:25 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_len(char *str)
{
	int	ctd;

	ctd = 0;
	while (str && str[ctd] && str[ctd] != '\n')
		ctd++;
	return (ctd);
}

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	int		ctd;
	int		ctd2;

	str = (char *)malloc(line_len(s1) + line_len(s2) + 1);
	if (!str)
		return (NULL);
	ctd = 0;
	while (s1 && s1[ctd])
	{
		str[ctd] = s1[ctd];
		ctd++;
	}
	ctd2 = 0;
	int newlineEncountered = 0; 
	while (s2[ctd2])
	{
		if (s2[ctd2] == '\n')
		{
			str[ctd + ctd2] = s2[ctd2];
			newlineEncountered = 1;
			break; 
		}
		else
		{
			str[ctd + ctd2] = s2[ctd2];
			ctd2++;
		}
	}
	str[ctd + ctd2] = '\0';
	return (str);
}

void	bufferclean(char *buffer)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	if (buffer[0] == '\n')
		buffer[0] = '\0';
	while (ctd < BUFFER_SIZE && buffer[ctd] != '\n')
	{
		buffer[ctd] = '\0';
		ctd++;
	}
	if (buffer[ctd] == '\n')
	{
		ctd2 = 0;
		while (ctd < BUFFER_SIZE)
		{
			buffer[ctd2] = buffer[ctd];
			ctd++;
			ctd2++;
		}
	}
}
