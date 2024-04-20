/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:49:04 by gfontao-          #+#    #+#             */
/*   Updated: 2024/04/15 16:01:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_bool	allocate_visited(t_map *map)
{
	int	ctd;

	map->visited = malloc(sizeof(t_bool *) * map->rows);
	if (map->visited == NULL)
		return (FALSE);
	ctd = map->rows;
	while (ctd--)
	{
		map->visited[ctd] = malloc(sizeof(t_bool) * map->cols);
		if (map->visited[ctd] == NULL)
		{
			while (ctd < map->rows)
				free(map->visited[ctd++]);
			free(map->visited);
			freemap(map, "Error allocating memory", 1);
		}
	}
	initialize_visited(map);
	return (TRUE);
}

void	initialize_visited(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (ctd < map->rows)
	{
		ctd2 = 0;
		while (ctd2 < map->cols)
		{
			map->visited[ctd][ctd2] = FALSE;
			ctd2++;
		}
		ctd++;
	}
}

void	free_matrix(t_map *map, int i, int max)
{
	while (i <= max)
		free(map->visited[i++]);
	free(map->visited);
}

t_bool	flood_fill(t_map *map, int x, int y)
{
	if (map->map[x][y] == '1' || map->visited[x][y] == TRUE)
		return (FALSE);
	else
		map->visited[x][y] = TRUE;
	if (map->map[x][y] == 'E')
		map->check.exit--;
	if (map->map[x][y] == 'C')
		map->check.collectibles--;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return (TRUE);
}

void	validate_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	check_map(map);
	check_line(map);
	ctd = -1;
	while (++ctd < map->rows)
	{
		ctd2 = 0;
		while (ctd2 < map->cols)
		{
			if (map->map[ctd][ctd2] == 'P')
			{
				map->check.player_x = ctd;
				map->check.player_y = ctd2;
			}
			if (ctd == 0 || ctd == map->rows - 1 || ctd2 == 0
				|| ctd2 == map->cols - 1)
			{
				if (map->map[ctd][ctd2] != '1')
					freemap(map, "Map must be surrounded by walls", 1);
			}
			ctd2++;
		}
	}
}
