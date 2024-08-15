#include "../../includes/headers/cub3d.h"

void	mlx_shutdown(t_session *instance)
{
	mlx_loop_end(instance->mlx_ser);
	if (instance->mlx_img.img)
		mlx_destroy_image(instance->mlx_ser, instance->mlx_img.img);
	destroy_textures(instance);
	if (instance->mlx_win)
	{
		mlx_destroy_window(instance->mlx_ser, instance->mlx_win);
		instance->mlx_win = NULL;
	}
	if (instance->mlx_ser)
	{
		mlx_destroy_display(instance->mlx_ser);
		free(instance->mlx_ser);
	}
	clean_parser(&instance->map);
	//free(instance); // maybe return ?
	exit(0);
}

void	mlx_update(t_session *instance)
{
	clear_image(instance);
	//raycast
	//debug2D(instance);
	camera3d(instance, instance->player.x, instance->player.y);
	//minimap
	vp_scaled(instance);
	//vp_grid(instance);
	//push to window
	mlx_put_image_to_window(instance->mlx_ser,
		instance->mlx_win, instance->mlx_img.img, 0, 0);
	// mlx_put_image_to_window(instance->mlx_ser,
	// 	instance->mlx_win, instance->textures[NORTH_TEXTURE].img, 0, 0);
}

void	mlx_startup(t_session *instance)
{
	// instance->width = W_WIDTH;
	// instance->height = W_HEIGHT;
	if (!mlx_vars_init(instance) || !instance->mlx_ser || !instance->mlx_win || !instance->mlx_img.img)
		mlx_shutdown(instance);
	//raycast
	//debug2D(instance);
	camera3d(instance, (double)instance->player.x, (double)instance->player.y);
	//minimap
	vp_scaled(instance);
	//vp_grid(instance);
	//push to window
	mlx_put_image_to_window(instance->mlx_ser, instance->mlx_win, instance->mlx_img.img, 0, 0);
	mlx_hook(instance->mlx_win, KeyPress, KeyPressMask, handle_key, instance);
	mlx_hook(instance->mlx_win, KeyRelease, KeyReleaseMask, handle_key_release, instance);
	mlx_hook(instance->mlx_win, ButtonPress, ButtonPressMask, ignore_mouse_keys, instance);
	mlx_hook(instance->mlx_win, MotionNotify, PointerMotionMask, mouse_movement, instance);
	mlx_loop_hook(instance->mlx_ser, const_movement, instance);  // Use instance->mlx instead of instance->mlx_win
	mlx_hook(instance->mlx_win, DestroyNotify, StructureNotifyMask, exit_hook, instance);
	mlx_loop(instance->mlx_ser);
}
