/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:05:26 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/16 12:59:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include "limits.h"
char	*get_next_line(int fd)
{
	static char		buffer [BUFFER_SIZE + 1];
	char			*str;
	int				ctd;

	ctd = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{	
		while (ctd <= BUFFER_SIZE)
			buffer[ctd++] = '\0';
		return (NULL);
	}
	str = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		buffer_clean(buffer);
		if (str[ft_linelen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
