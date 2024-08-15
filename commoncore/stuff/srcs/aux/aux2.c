#include "../../includes/headers/cub3d.h"

int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

bool	is_in_colision(int x, int y, t_session *instane, char type)
{
	int	ctd;
	t_map *map;

	map = &instane->map;
	ctd = 0;
	if (type == 'D' && instane->player.door == true)
		return (false);
	while (ctd <= PLAYER_SIZE)
	{
		if (map->grid[y][x + ctd] == type || map->grid[y + ctd][x] == type || map->grid[y + ctd][x + ctd] == type)
			return (true);
		if (map->grid[y - ctd][x] == type || map->grid[y][x - ctd] == type || map->grid[y - ctd][x - ctd] == type)
			return (true);
		ctd++;
	}
	return (false);
}

void	check_time(void)
{
	struct timeval		tv;
	long long			current_time;
	static long long	last_time = 0;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * (long)1000) + (tv.tv_usec / 1000);
	if (last_time && current_time - last_time <= FRAME_TIME)
		usleep(FRAME_TIME - (current_time - last_time <= FRAME_TIME));
	gettimeofday(&tv, NULL);
	last_time = (tv.tv_sec * (long)1000) + (tv.tv_usec / 1000);
}
