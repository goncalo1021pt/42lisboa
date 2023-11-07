/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:21:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/16 11:19:37 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer [FOPEN_MAX][BUFFER_SIZE + 1];
	char			*str;
	int				ctd;

	ctd = 0;
	if (read(fd, 0, 0) < 0 || FOPEN_MAX <= fd || BUFFER_SIZE <= 0)
	{
		if (fd > 0 && FOPEN_MAX > fd)
			while (buffer[fd][ctd])
				buffer[fd][ctd++] = '\0';
		return (NULL);
	}
	str = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_join_line(str, buffer[fd]);
		line_buffer_clean(buffer[fd]);
		if (str[ft_linelen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
