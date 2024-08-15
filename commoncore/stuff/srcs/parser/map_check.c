#include "../../includes/headers/cub3d.h"

bool	check_char(t_map *map)
{
	int	ctd;
	int	ctd2;
	int	player_count;

	ctd = 0;
	player_count = 0;
	while (map->map[ctd])
	{
		ctd2 = 0;
		while (map->map[ctd][ctd2])
		{
			if (!is_in_array(VALID_CHAR, map->map[ctd][ctd2]))
				return (ft_putendl_fd(INV_CHAR, 2), false);
			if (is_in_array(PLAYER, map->map[ctd][ctd2]))
				player_count++;
			if (player_count > 1)
				return (ft_putendl_fd(INV_PLAYER, 2), false);
			ctd2++;
		}
		ctd++;
	}
	if (player_count == 0)
		return (ft_putendl_fd(INV_PLAYER, 2), false);
	return (true);
}

void	set_visited(t_map *map)
{
	int	cols;
	int	rows;

	cols = 0;
	while (map->map[cols])
	{
		rows = 0;
		while (map->map[cols][rows])
		{
			map->visited[cols][rows] = false;
			rows++;
		}
		cols++;
	}
}

bool	initiate_flood(t_map *map)
{
	int	cols;
	int	rows;

	cols = 0;
	while (map->map[cols])
		cols++;
	map->visited = calloc(sizeof(bool *), cols + 1);
	if (!map->visited)
		return (ft_putendl_fd(ERR_ALLOC, 2), false);
	cols--;
	while (cols >= 0)
	{
		rows = 0;
		while (map->map[cols][rows])
			rows++;
		map->visited[cols] = malloc(rows * sizeof(bool));
		if (!map->visited[cols])
			return (ft_putendl_fd(ERR_ALLOC, 2), false);
		cols--;
	}
	set_visited(map);
	return (true);
}

bool	flood_fill(t_map *map, int cols, int rows)
{
	if (cols < 0 || rows < 0 || !map->map[cols]
		|| rows >= (int)ft_strlen(map->map[cols])
		|| map->map[cols][rows] == ' ')
		return (false);
	if (map->map[cols][rows] == '1' || map->visited[cols][rows])
		return (true);
	map->visited[cols][rows] = true;
	if (!flood_fill(map, cols + 1, rows))
		return (false);
	if (!flood_fill(map, cols - 1, rows))
		return (false);
	if (!flood_fill(map, cols, rows + 1))
		return (false);
	if (!flood_fill(map, cols, rows - 1))
		return (false);
	return (true);
}

bool	check_sorroundings(t_map *map)
{
	int	cols;
	int	rows;

	cols = 0;
	while (map->map[cols])
	{
		rows = 0;
		while (map->map[cols][rows])
		{
			if ((map->map[cols][rows] == '0' || is_in_array(PLAYER,
						map->map[cols][rows]))
				&& map->visited[cols][rows] == false)
			{
				if (!flood_fill(map, cols, rows))
					return (ft_putendl_fd(ERR_MAP, 2), false);
			}
			rows++;
		}
		cols++;
	}
	return (true);
}
