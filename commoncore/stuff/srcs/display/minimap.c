#include "../../includes/headers/cub3d.h"

void fill_square(t_session *instance, t_point point, int sq, int color)
{
	int	x;
	int	y;
	y = point.y;
	while (y < point.y + sq)
	{
		x = point.x;
		while ( x < point.x + sq)
		{
			pixel_put(instance, x, y, color);
			x++;
		}
		y++;
	}
}

// draw square faces counter clockwise start tih the top border
void	draw_square(t_session *instance, t_point point, int sq, int color)
{
	t_point	start;
	t_point end;

	start = point;
	end.x = point.x + sq;
	end.y = point.y;
	draw_line(instance, start, end, color);
	end.x = point.x;
	end.y = point.y + sq;
	draw_line(instance, start, end, color);
	start.x = point.x;
	start.y = point.y + sq;
	end.x = point.x + sq;
	end.y = point.y + sq;
	draw_line(instance, start, end, color);
	start.x = point.x + sq;
	start.y = point.y;
	end.x = point.x + sq;
	end.y = point.y + sq;
	draw_line(instance, start, end, color);
}

void	draw_face(t_session *instance, int x, int y, int color)
{
	int		length;
	t_point	end;

	length = MAP_SCALE / 4;
	end.y = y + length * sin(instance->player.angle * PI / 180);
	end.x = x + length * cos(instance->player.angle * PI / 180);
	draw_line(instance, (t_point){x, y}, end, color);
}

void	init_camera2d(t_session *instance, t_camera2d *cam2d)
{
	cam2d->size.x = instance->width / 5;
	cam2d->size.y = instance->height / 5;
	cam2d->p_pos.x = instance->player.x;
	cam2d->p_pos.y = instance->player.y;
	cam2d->top_l.x = fmax(0, instance->player.x - cam2d->size.x / 2);
	cam2d->top_l.y = fmax(0, instance->player.y - cam2d->size.y / 2);
	cam2d->bot_r.x = fmin(instance->width - 1, instance->player.x + cam2d->size.x / 2);
	cam2d->bot_r.y = fmin(instance->height - 1, instance->player.y + cam2d->size.y / 2);
}

void	vp_player(t_session *instance, int x, int y)
{
	t_point	pos;
	int		sq;

	sq = MAP_SCALE / 4;
	pos.y = y - (sq / 2);
	pos.x = x - (sq / 2);
	fill_square(instance, pos, sq, 0x000000);
	draw_square(instance, pos, sq, 0xffffff);
	draw_face(instance, x, y, 0xff4500);
}

# define H_SCALE instance->height / 7
# define W_SCALE instance->width / 8

void vp_scaled(t_session *instance)
{
	int	y;
	int	x;
	t_camera2d	cam2d;

	if (instance->mode.type == PLAY && instance->mode.sub != MINIMAP)
		return ;
	init_camera2d(instance, &cam2d);
	y = cam2d.top_l.y;
	while (y < cam2d.bot_r.y && instance->map.grid[y])
	{
		cam2d.offset.y = (y - cam2d.top_l.y) + (H_SCALE  - (instance->player.y - cam2d.top_l.y));
		x = cam2d.top_l.x;
		while (x < cam2d.bot_r.x && instance->map.grid[y][x])
		{
			cam2d.offset.x = (x - cam2d.top_l.x) + (W_SCALE - (instance->player.x - cam2d.top_l.x));
			if (instance->map.grid[y][x] == '1')
				pixel_put(instance, cam2d.offset.x, cam2d.offset.y, 0x004550);
			else if (instance->map.grid[y][x] == '0')
				pixel_put(instance, cam2d.offset.x, cam2d.offset.y, 0xffffff);
			// else if (instance->map.grid[y][x] == 'D')
			// 	pixel_put(instance, cam2d.offset.x, cam2d.offset.y, 0x000000);
			x++;
		}
		y++;
	}
	vp_player(instance, W_SCALE, H_SCALE);
}


void vp_grid(t_session *instance)
{
	int			y;
	int			x;
	t_camera2d	cam2d;

	init_camera2d(instance, &cam2d);
	y = fmax(0, (cam2d.top_l.y - MAP_SCALE));
	while (y < cam2d.bot_r.y && instance->map.grid[y])
	{
		cam2d.offset.y = (y - cam2d.top_l.y) + (MAP_SCALE * 3.5  - (instance->player.y - cam2d.top_l.y));
		x = fmax(0, (cam2d.top_l.x - MAP_SCALE));
		while (x < cam2d.bot_r.x && instance->map.grid[y][x])
		{
			cam2d.offset.x = (x - cam2d.top_l.x) + (MAP_SCALE * 3.5 - (instance->player.x - cam2d.top_l.x));
			if (instance->map.grid[y][x] == '1' && (x % MAP_SCALE == 0 && y % MAP_SCALE == 0))
			{
				fill_square(instance, cam2d.offset, MAP_SCALE, 0xff4500 / 2);
				draw_square(instance, cam2d.offset, MAP_SCALE, 0x000000);
			}
			x++;
		}
		y++;
	}
	vp_player(instance, MAP_SCALE * 3.5, MAP_SCALE * 3.5);
}


