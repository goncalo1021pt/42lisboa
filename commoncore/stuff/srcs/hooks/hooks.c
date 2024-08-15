#include "../../includes/headers/cub3d.h"

int	exit_hook(t_session *instance)
{
	mlx_shutdown(instance);
	return (0);
}

int	handle_key(int keycode, t_session *instance)
{
	if (keycode == XK_Left)
		instance->keys[LEFT_ARROW] = 1;
	else if (keycode == XK_Right)
		instance->keys[RIGHT_ARROW] = 1;
	else if (keycode == XK_Shift_L)
		instance->keys[L_SHIFT] = 1;
	else if (keycode == XK_Escape)
		mlx_shutdown(instance);
	if (keycode == XK_a)
		instance->keys[A] = 1;
	else if (keycode == XK_d)
		instance->keys[D] = 1;
	else if (keycode == XK_w)
		instance->keys[W] = 1;
	else if (keycode == XK_s)
		instance->keys[S] = 1;
	else
		return (0);
	instance->player.keys_pressed++;
	return (0);
}

int	handle_key_release(int keycode, t_session *instance)
{
	if (keycode == XK_Left)
		instance->keys[LEFT_ARROW] = 0;
	else if (keycode == XK_Right)
		instance->keys[RIGHT_ARROW] = 0;
	else if (keycode == XK_Shift_L)
		instance->keys[L_SHIFT] = 0;
	else if (keycode == XK_p)
		handle_mode(keycode, instance);
	else if (keycode == XK_Tab)
		handle_mode(keycode, instance);
	if (keycode == XK_e)
		handle_door(instance);
	if (keycode == 'a')
		instance->keys[A] = 0;
	else if (keycode == 'd')
		instance->keys[D] = 0;
	else if (keycode == 'w')
		instance->keys[W] = 0;
	else if (keycode == 's')
		instance->keys[S] = 0;
	else
		return (0);
	instance->player.keys_pressed--;
	return (0);
}

int	const_movement(t_session *instance)
{
	int	speed;

	if (instance->mode.type == PAUSE)
		return (0);
	speed = get_player_speed(instance);
	if (instance->keys[W])
		move_player(&instance->player, instance, speed, W_ANGLE);
	if (instance->keys[S])
		move_player(&instance->player, instance, speed, S_ANGLE);
	if (instance->keys[A])
		move_player(&instance->player, instance, speed, A_ANGLE);
	if (instance->keys[D])
		move_player(&instance->player, instance, speed, D_ANGLE);
	if (instance->keys[LEFT_ARROW])
		rotate_player(&instance->player, LEFT_ARROW);
	if (instance->keys[RIGHT_ARROW])
		rotate_player(&instance->player, RIGHT_ARROW);
	check_time();
	mlx_update(instance);
	return (0);
}
