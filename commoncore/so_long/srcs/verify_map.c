/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:49:04 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/27 15:52:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	allocate_matrix(t_map *map)
{
	int	ctd;

	map->rows = sizeof(map->map[0]);
	map->cols = sizeof(map->map) / sizeof(char *);
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
	unsigned int	line_len;

	line_len = ft_strlen(map->map[0]);
	ctd = 0;
	check_map(map);
	while (map->map[ctd])
	{
		if ((ft_strlen(map->map[ctd]) != line_len) || line_len < 3)
			freemap(map, "Map must be rectangular", 1);
		if (check_line(map->map[ctd]) == FALSE)
			freemap(map, "Invalid character in map", 1);
		ctd++;
	}
	ctd2 = 0;
	(void)ctd2;
	while (map->map[0][ctd2])
	{
		if (map->map[0][ctd2] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (map->map[ctd - 1][ctd2])
	{
		if (map->map[ctd - 1][ctd2] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (ctd2 < ctd && map->map[ctd2][0])
	{
		if (map->map[ctd2][0] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (ctd2 < ctd && map->map[ctd2][line_len - 1])
	{
		if (map->map[ctd2][line_len - 1] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ft_printf("Map validated\n");
}
