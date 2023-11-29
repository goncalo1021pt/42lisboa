/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:08 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 11:43:11 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	freemap(t_map *map, char *str, int status)
{
	int	ctd;

	ctd = 0;
	while (map->map[ctd])
		free(map->map[ctd++]);
	free(map->map);
	if (status == 1)
		error_message(str);
	else
		exit(0);
}
