#include "../../includes/headers/cub3d.h"

void	init_camera3D(t_session *instance, t_camera3D *camera)
{
	camera->dir_x = cos(instance->player.angle * (PI / 180));
	camera->dir_y = sin(instance->player.angle * (PI / 180));
	camera->fov = 78 * (PI / 180);
	camera->plane_x = -camera->dir_y * tan(camera->fov / 2);
	camera->plane_y = camera->dir_x * tan(camera->fov / 2);
}
int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4); // (data->bpp / 8) = 4;
	return (*(unsigned int *)dst);
}

void draw_textured_line(t_session *instance, t_point start, t_point end, t_texture *tex)
{
	t_dda dda;
	int i;

	i = 0;
	init_dda(&dda, start, end);
	i = -dda.current_y / dda.y_inc;
	dda.current_y = 0;
	tex->x = tex->wall_x * tex->data->width / MAP_SCALE;
	while (i < dda.step) // cant be <=
	{
		tex->y = (i / dda.step) * tex->data->height;
		if (tex->y >= 0 && tex->y <= tex->data->height
			&& dda.current_y >= 0 && dda.current_y <= instance->height)
		{
			tex->color = get_pixel(tex->data, tex->x, tex->y);
			if (tex->color != 0xF900FF)
				pixel_put(instance, dda.current_x, dda.current_y, tex->color);
		}
		dda.current_y += dda.y_inc;
		if (dda.current_y > instance->height)
			break;
		i++;
	}
}
void	cast_aux_ray(t_session *instance, t_ray	*ray)
{
	int	hit;

	hit = 0;
	ray->door = false;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->y += ray->step_y;
			ray->side = 1;
		}
		if (instance->map.grid[ray->y][ray->x] == 'D')
		{
			ray->door= true;
			break ;
		}
	}
	ray->wall_dir = get_wall_dir(instance->map.grid, ray->x, ray->y, ray->side);
	ray->perp_wall_dist = get_pwall_distance(ray);
}

int	get_walx(t_ray *ray, double pos_x, double pos_y)
{
	if (ray->wall_dir == EAST_TEXTURE || ray->wall_dir == WEST_TEXTURE)
		return (pos_y + ray->perp_wall_dist * ray->ray_dir_y );
	else
		return (pos_x + ray->perp_wall_dist * ray->ray_dir_x );
}

void	rndr_doors(t_session *instance, t_camera3D camera, int i, double pos_x, double pos_y)
{
	t_slice		slice;
	t_texture	tex;

	init_ray(&camera, &instance->aux_ray, i, (t_point){pos_x, pos_y});
	aim_ray(&instance->aux_ray, pos_x, pos_y);
	cast_aux_ray(instance, &instance->aux_ray);
	slice.height = (int)(instance->height / instance->aux_ray.perp_wall_dist * MAP_SCALE);
	slice.start = -slice.height / 2 + instance->height / 2;
	slice.end = slice.height / 2 + instance->height / 2;
	instance->aux_ray.wall_x = get_walx(&instance->aux_ray, pos_x, pos_y);
	tex.wall_x = floor(instance->aux_ray.wall_x % MAP_SCALE);
	tex.data = get_tex_data(instance, &instance->aux_ray, true);
	draw_textured_line(instance, (t_point){i, slice.start}, (t_point){i, slice.end}, &tex);
}

void	camera3d(t_session *instance, double pos_x, double pos_y)
{
	t_camera3D	camera;
	t_ray		ray;
	t_slice		slice;
	t_texture	tex;
	int	i;

	init_camera3D(instance, &camera);
	i = 0;
	while (i < instance->width)
	{
		init_ray(&camera, &ray, i, (t_point){pos_x, pos_y});
		aim_ray(&ray, pos_x, pos_y);
		cast_ray(instance, &ray);
		slice.height = (int)(instance->height / ray.perp_wall_dist * MAP_SCALE);
		slice.start = -slice.height / 2 + instance->height / 2;
		slice.end = slice.height / 2 + instance->height / 2;
		ray.wall_x = get_walx(&ray, pos_x, pos_y);
		tex.wall_x = floor(ray.wall_x % MAP_SCALE);
		tex.data = get_tex_data(instance, &ray, false);
		draw_textured_line(instance, (t_point){i, slice.start}, (t_point){i, slice.end}, &tex);
		if (ray.door)
			rndr_doors(instance, camera, i, pos_x, pos_y);
		i++;
	}
}

			// init_ray(&camera, &instance->aux_ray, i, (t_point){pos_x, pos_y});
			// aim_ray(&instance->aux_ray, pos_x, pos_y);
			// cast_aux_ray(instance, &instance->aux_ray);
			// slice.height = (int)(instance->height / instance->aux_ray.perp_wall_dist * MAP_SCALE);
			// slice.start = -slice.height / 2 + instance->height / 2;
			// slice.end = slice.height / 2 + instance->height / 2;
			// instance->aux_ray.wall_x = get_walx(&instance->aux_ray, pos_x, pos_y);
			// tex.wall_x = floor(instance->aux_ray.wall_x % MAP_SCALE);
			// tex.data = get_tex_data(instance, &instance->aux_ray, true);
			// draw_textured_line(instance, (t_point){i, slice.start}, (t_point){i, slice.end}, &tex);
