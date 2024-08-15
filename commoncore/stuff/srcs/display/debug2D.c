#include "../../includes/headers/cub3d.h"

static void draw_grid(t_session *instance)
{
	int			y;
	int			x;

	y = 0;
	while (instance->map.grid[y])
	{
		x = 0;
		while (instance->map.grid[y][x])
		{
			if (instance->map.grid[y][x] == '1' && (x % MAP_SCALE == 0 && y % MAP_SCALE == 0))
				draw_square(instance, ((t_point){x, y}), MAP_SCALE, 0x000000);
			x++;
		}
		y++;
	}
}

void	debug2D(t_session *instance)
{
	int			y;
	int			x;

	y = 0;
	while (instance->map.grid[y])
	{
		x = 0;
		while (instance->map.grid[y][x])
		{
			if (instance->map.grid[y][x] == '1')
				pixel_put(instance, x, y, 0xff4500);
			else if (instance->map.grid[y][x] == '0')
				pixel_put(instance, x, y, 0xffffff);
			x++;
		}
		y++;
	}
	draw_grid(instance);
}
