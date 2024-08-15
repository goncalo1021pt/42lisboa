#include "../../includes/headers/cub3d.h"

void	print_player(t_player *player)
{
	ft_printf("x: %d | y: %d\n", player->x, player->y);
	printf("angle: %lf\n", player->angle);
}

void	init_keys(t_session *instance)
{
	int	i;

	i = 0;
	while (i < MAX_KEYS)
	{
		instance->keys[i] = 0;
		i++;
	}
}

void	set_angle(t_player *player, char angle)
{
	if (angle == 'N')
		player->angle = NORTH;
	else if (angle == 'E')
		player->angle = EAST;
	else if (angle == 'S')
		player->angle = SOUTH;
	else if (angle == 'W')
		player->angle = WEST;
}

bool	initialize_player(t_player *player, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	player->keys_pressed = 0;
	player->door = false;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (is_in_array(PLAYER, map->grid[y][x]))
			{
				player->x = x;
				player->y = y;
				set_angle(player, map->grid[y][x]);
				return (true);
			}
		}
	}
	return (true);
}

bool	start_game(t_session *instance)
{
	t_map		*map;
	t_player	*player;

	map = &instance->map;
	player = &instance->player;
	if (!create_grid(map))
		return (false);
	if (!initialize_player(player, map))
		return (false);
	// print_grid(map->grid);
	init_keys(instance);
	mlx_startup(instance);
	// print_player(player);
	return (true);
}
