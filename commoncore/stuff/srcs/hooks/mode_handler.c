#include "../../includes/headers/cub3d.h"

int	handle_mode(int keycode, t_session *instance)
{
	if (keycode == XK_p)
	{
		if (instance->mode.type == PAUSE)
		{
			instance->mode.type = PLAY;
			mlx_mouse_hide(instance->mlx_ser, instance->mlx_win);
		}
		else
		{
			instance->mode.type = PAUSE;
			mlx_mouse_show(instance->mlx_ser, instance->mlx_win);
			pause_menu(instance);
		}
	}
	else if (keycode == XK_Tab && instance->mode.type == PLAY && instance->mode.sub == DEFAULT)
		instance->mode.sub = MINIMAP;
	else if (keycode == XK_Tab && instance->mode.type == PLAY && instance->mode.sub == MINIMAP)
		instance->mode.sub = DEFAULT;
	return (0);
}

void	handle_door(t_session *instance)
{
	struct timeval		tv;

	if (!instance->player.door)
		return ;
	gettimeofday(&tv, NULL);
	instance->player.time_door = tv.tv_sec;
}

// bool close_door(t_session *instance)
// {
// 	if (instance->player.time_door)
		
// }
