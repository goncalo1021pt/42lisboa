#include "../../includes/headers/cub3d.h"

bool	is_border(char **map, int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0 || x + 1 >= (int)ft_strlen(map[y]) || y
		+ 1 >= ft_strslen(map))
		return (true);
	return (false);
}

bool	check_placement(char **map, int x, int y)
{
	if (is_border(map, x, y))
		return (ft_putendl_fd(INV_DOOR, 2), false);
	if (map[y][x - 1] == '0' && map[y][x + 1] == '0' && map[y - 1][x] == '1'
		&& map[y + 1][x] == '1')
		return (true);
	else if (map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y
			- 1][x] == '0' && map[y + 1][x] == '0')
		return (true);
	else
		return (ft_putendl_fd(INV_DOOR, 2), false);
}

bool	check_doors(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'D')
			{
				if (!check_placement(map->map, x, y))
					return (false);
			}
		}
	}
	return (true);
}
