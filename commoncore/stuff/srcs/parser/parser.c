#include "../../includes/headers/cub3d.h"

bool	check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	name = name + len - 4;
	if (len < 4 || ft_strncmp(name, ".cub", 4))
		return (ft_putendl_fd(INV_MAPNAME, 2), false);
	return (true);
}

bool	read_file(t_map *map, int fd, int loopn)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		if (!read_file(map, fd, loopn + 1))
			return (false);
	}
	else
	{
		map->buffer = ft_calloc((loopn + 1), sizeof(char *));
		if (!map->buffer)
			return (false);
	}
	if (map->buffer != NULL)
	{
		map->buffer[loopn] = ft_strtrim(line, "\n");
		free(line);
		return (true);
	}
	return (false);
}

bool	get_file(char *name, t_map *map)
{
	int		fd;
	char	*new_name;

	new_name = ft_strjoin("includes/maps/", name);
	if (!new_name)
		return (ft_putendl_fd(ERR_ALLOC, 2), false);
	fd = open(new_name, O_RDONLY);
	free(new_name);
	if (fd < 0)
		return (ft_putendl_fd(INV_FILE, 2), false);
	if (!read_file(map, fd, 0))
		return (close(fd), ft_putendl_fd(ERR_FILE, 2), false);
	close(fd);
	return (true);
}

bool	validate_map(t_map *map)
{
	if (!check_char(map))
		return (false);
	if (!check_doors(map))
		return (false);
	if (!initiate_flood(map))
		return (false);
	if (!check_sorroundings(map))
		return (false);
	return (true);
}

bool	parser(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		return (ft_putendl_fd(INV_ARGS, 2), false);
	if (!check_name(argv[1]))
		return (false);
	if (!get_file(argv[1], map))
		return (false);
	if (!get_args(map))
		return (false);
	if (!validate_map(map))
		return (false);
	if (!validate_textures(map))
		return (false);
	return (true);
}
