/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:24:45 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/07 12:37:51 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	if (*buffer)
	{
		str = strjoin(str, buffer);
		bufferclean(buffer);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = strjoin(str, buffer);
		//printf(":%c\n", str[line_len(str) - 1]);
		bufferclean(buffer);
		if (str[line_len(str)] == '\n')
			return (str);
	}
	return (str);
}
