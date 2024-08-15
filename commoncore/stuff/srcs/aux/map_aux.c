#include "../../includes/headers/cub3d.h"

void	free_file(char **arr_str)
{
	int	ctd;

	ctd = 0;
	while (arr_str[ctd])
	{
		free(arr_str[ctd]);
		ctd++;
	}
	free(arr_str);
}

void	print_file(t_map *map)
{
	int	ctd;

	ctd = 0;
	printf("NO: %s\n", map->no);
	printf("SO: %s\n", map->so);
	printf("WE: %s\n", map->we);
	printf("EA: %s\n", map->ea);
	printf("C: %s\n", map->c);
	printf("F: %s\n", map->f);
	while (map->map[ctd])
	{
		ft_printf("%s\n", map->map[ctd]);
		ctd++;
	}
}

void	init_map(t_map *map)
{
	map->buffer = NULL;
	map->map = NULL;
	map->visited = NULL;
	map->grid = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c = NULL;
	map->f = NULL;
}

void	print_grid(char **grid)
{
	int	ctd;

	ctd = 0;
	while (grid[ctd])
	{
		ft_printf("%s\n", grid[ctd]);
		ctd++;
	}
}

void	create_boarder(char **grid)
{
	int	x;
	int	y;

	x = 0;
	while (grid[x])
	{
		y = 0;
		while (grid[x][y])
		{
			if (grid[x][y] == '0' && (grid[x][y + 1] == '1' || grid[x][y
					- 1] == '1' || grid[x + 1][y] == '1' || grid[x
					- 1][y] == '1'))
				grid[x][y] = '2';
			if (grid[x][y] == '0' && (grid[x][y + 2] == '1' || grid[x][y
					- 2] == '1' || grid[x + 2][y] == '1' || grid[x
					- 2][y] == '1'))
				grid[x][y] = '2';
			y++;
		}
		x++;
	}
}
