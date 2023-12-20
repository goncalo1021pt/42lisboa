/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:45:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 14:34:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = -1;
	map->check.player = 0;
	map->check.exit = 0;
	map->collectibles_count = 0;
	while (map->map[++ctd])
	{
		ctd2 = -1;
		while (map->map[ctd][++ctd2])
		{
			if (ft_strchr(LEGAL_CHARS, map->map[ctd][ctd2]) == NULL)
				freemap(map, "Invalid character in map", 1);
			if (map->map[ctd][ctd2] == 'P')
				map->check.player++;
			else if (map->map[ctd][ctd2] == 'E')
				map->check.exit++;
			else if (map->map[ctd][ctd2] == 'C')
				map->collectibles_count++;
		}
	}
	map_verefications(map);
}

void	map_verefications(t_map *map)
{
	if (map->check.player != 1)
		freemap(map, "Invalid number of players", 1);
	if (map->check.exit != 1)
		freemap(map, "Invalid number of exits", 1);
	if (map->collectibles_count < 1)
		freemap(map, "Invalid number of collectibles", 1);
}
