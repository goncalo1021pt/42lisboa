/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:05:26 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/07 11:01:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*get_next_line(int fd)
{
	static char		buffer [BUFFER_SIZE + 1];
	char			*str;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	if (buffer[0])
	{
		str = ft_strjoin(str, buffer);
		buffer_clean(buffer);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		buffer_clean(buffer);
		if (str[ft_linelen(str)] == '\n')
			return (str);
	}
	return (str);
}
