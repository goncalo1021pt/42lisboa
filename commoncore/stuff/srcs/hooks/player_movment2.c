#include "../../includes/headers/cub3d.h"

float	get_player_speed(t_session *instance)
{
	float	speed;

	speed = SPEED_MULTIPLIER;
	if (instance->player.keys_pressed > 1)
		speed *= 0.5;
	if (instance->keys[L_SHIFT])
		speed *= 1.5;
	return (speed);
}
