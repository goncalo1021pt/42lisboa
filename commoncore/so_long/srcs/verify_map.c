/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:49:04 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/28 11:16:33 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	allocate_matrix(t_map *map)
{
	int	ctd;

	/* map->rows = sizeof(map->map[0]);
	map->cols = sizeof(map->map) / sizeof(char *); */
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
	while (ctd++ < map->rows)
		ft_memset(map->visited[ctd], FALSE, map->cols);
	return (TRUE);
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
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return (TRUE);
}

void	validate_map(t_map *map)
{
	int				ctd;
	int				ctd2;

	check_map(map);
	check_line(map);
	ctd = 0;
	while (ctd < map->rows)
	{
		ctd2 = 0;
		while (ctd2 < map->cols)
		{
			if (ctd == 0 || ctd == map->rows - 1 || ctd2 == 0 || ctd2 == map->cols - 1)
			{
				if (map->map[ctd][ctd2] != '1')
					freemap(map, "Map must be surrounded by walls", 1);
			}
			ctd2++;
		}
		ctd++;
	}
	ft_printf("Map validated\n");
}
