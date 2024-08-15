#include "../../includes/headers/cub3d.h"

double	clamp_ray(double dir)
{
	if (dir == 0)
		return (1e30);
	else
		return (fabs(1 / dir));
}

double	get_pwall_distance(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}
int get_wall_dir(char **grid ,int x, int y, int side)
{
	if (grid[y + 1][x] != '1' && side == 1)
		return (SOUTH_TEXTURE);
	else if (grid[y - 1][x] != '1' && side == 1)
		return (NORTH_TEXTURE);
	else if (grid[y][x + 1] != '1' )
		return (EAST_TEXTURE);
	else
		return (WEST_TEXTURE);
}
t_data	*get_tex_data(t_session *instance, t_ray *ray, bool select)
{
		if (ray->door && select)
			return (&instance->textures[DOOR_TEXTURE_1]);
		else if (ray->wall_dir == NORTH_TEXTURE)
			return (&instance->textures[NORTH_TEXTURE]);
		else if (ray->wall_dir == SOUTH_TEXTURE)
			return (&instance->textures[SOUTH_TEXTURE]);
		else if (ray->wall_dir == EAST_TEXTURE)
			return (&instance->textures[EAST_TEXTURE]);
		else if (ray->wall_dir == WEST_TEXTURE)
			return (&instance->textures[WEST_TEXTURE]);
		return (NULL);
}
