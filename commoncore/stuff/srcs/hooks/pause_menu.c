#include "../../includes/headers/cub3d.h"

# define BOARDER_SIZE MAP_SCALE * 2

int	interpolate(float ratio, int start, int end)
{
	return (start * (1 - ratio) + end * ratio);
}

int	create_rgb(float ratio, int start, int end)
{
	int	r;
	int	g;
	int	b;

	r = interpolate(ratio, (start >> 16) & 0xFF, (end >> 16) & 0xFF);
	g = interpolate(ratio, (start >> 8) & 0xFF, (end >> 8) & 0xFF);
	b = interpolate(ratio, start & 0xFF, end & 0xFF);
	return ((r << 16) | (g << 8) | b);
}

void	pause_menu(t_session *instance)
{
	int	x;
	int	y;

	x = BOARDER_SIZE;
	while (x < instance->width - BOARDER_SIZE)
	{
		y = BOARDER_SIZE;
		while (y < instance->height - BOARDER_SIZE)
		{
			if ((x > BOARDER_SIZE && x < instance->width - BOARDER_SIZE - 1) && (y > BOARDER_SIZE || y < instance->height - BOARDER_SIZE - 1))
				pixel_put(instance, x, y, 0x0000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(instance->mlx_ser, instance->mlx_win, instance->mlx_img.img, 0, 0);
}
