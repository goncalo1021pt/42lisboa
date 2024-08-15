#include "../../includes/headers/cub3d.h"

bool	check_loaded_textures(t_map *map)
{
	if (map->no == NULL || map->so == NULL || map->we == NULL
		|| map->ea == NULL)
		return (false);
	if (map->c == NULL || map->f == NULL)
		return (false);
	return (true);
}

bool	set_texture(char *line, t_map *map)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (ft_putendl_fd(ERR_ALLOC, 2), false);
	if (split[0])
	{
		if (split[1] == NULL || ft_strslen(split) != 2)
			return (ft_free_split(split), false);
		if (map->no == NULL && ft_strncmp(split[0], "NO", 3) == 0)
			map->no = ft_strdup(split[1]);
		else if (map->so == NULL && ft_strncmp(split[0], "SO", 3) == 0)
			map->so = ft_strdup(split[1]);
		else if (map->we == NULL && ft_strncmp(split[0], "WE", 3) == 0)
			map->we = ft_strdup(split[1]);
		else if (map->ea == NULL && ft_strncmp(split[0], "EA", 3) == 0)
			map->ea = ft_strdup(split[1]);
		else if (map->c == NULL && ft_strncmp(split[0], "C", 2) == 0)
			map->c = ft_strdup(split[1]);
		else if (map->f == NULL && ft_strncmp(split[0], "F", 2) == 0)
			map->f = ft_strdup(split[1]);
		else
			return (ft_free_split(split), false);
	}
	return (ft_free_split(split), true);
}

char	*tabs_to_spaces(char *line)
{
	int	ctd;

	ctd = -1;
	while (line[++ctd])
	{
		if (line[ctd] == '\t')
			line[ctd] = ' ';
	}
	return (line);
}

bool	set_map(t_map *map, int ctd)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	while (map->buffer[ctd + len + temp])
	{
		if (map->buffer[ctd + len + temp][0] != '\0')
			len++;
		else
			temp++;
	}
	map->map = ft_calloc(len + 1, sizeof(char *));
	if (!map->map)
		return (ft_putendl_fd(ERR_ALLOC, 2), false);
	while (len--)
	{
		map->map[len] = ft_strdup(map->buffer[ctd + len + temp]);
		if (!map->map[len])
			return (ft_putendl_fd(ERR_ALLOC, 2), false);
	}
	return (true);
}

bool	get_args(t_map *map)
{
	int	ctd;

	ctd = 0;
	while (!check_loaded_textures(map))
	{
		if (!map->buffer[ctd])
			return (ft_putendl_fd(ERR_TEXTURE, 2), false);
		if (map->buffer[ctd][0] == '\0')
		{
			ctd++;
			continue ;
		}
		if (!set_texture(tabs_to_spaces(map->buffer[ctd]), map))
			return (ft_putendl_fd(ERR_TEXTURE, 2), false);
		ctd++;
	}
	if (!set_map(map, ctd))
		return (false);
	return (true);
}
