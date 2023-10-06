/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:05:26 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/06 11:24:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer [BUFFER_SIZE + 1];
	char			*str;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	str = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0 && buffer[0])
	{
		str = ft_strjoin(str, buffer);
		if (str[ft_linelen(str)] == '\n')
		{
			return (str);
		}
	}
	return (str);
}
