#include "../../includes/headers/cub3d.h"

bool	try_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	is_rgb(char *str)
{
	char	**rgb;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (ft_putendl_fd(ERR_ALLOC, 2), false);
	if (ft_strslen(rgb) != 3)
		return (free_file(rgb), false);
	if (!is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
		return (free_file(rgb), false);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		return (free_file(rgb), false);
	if (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		return (free_file(rgb), false);
	if (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
		return (free_file(rgb), false);
	free_file(rgb);
	return (true);
}

bool	convert_rgb(t_map *map)
{
	map->colors[0] = get_hexa_color(map->c);
	map->colors[1] = get_hexa_color(map->f);
	if (map->colors[0] < 0 || map->colors[1] < 0)
		return (false);
	return (true);
}

bool	validate_textures(t_map *map)
{
	if (!try_open(map->no))
		return (ft_putendl_fd(INV_NO, 2), false);
	if (!try_open(map->so))
		return (ft_putendl_fd(INV_SO, 2), false);
	if (!try_open(map->we))
		return (ft_putendl_fd(INV_WE, 2), false);
	if (!try_open(map->ea))
		return (ft_putendl_fd(INV_EA, 2), false);
	if (!is_rgb(map->c))
		return (ft_putendl_fd(INV_C, 2), false);
	if (!is_rgb(map->f))
		return (ft_putendl_fd(INV_F, 2), false);
	if (!convert_rgb(map))
		return (false);
	return (true);
}
