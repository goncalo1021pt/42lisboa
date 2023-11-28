/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:39 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/28 14:54:28 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_line(t_map *map)
{
	int	ctd;

	map->cols = ft_strlen(map->map[0]);
	ctd = 0;
	while (ctd < map->rows)
		if (ft_strlen(map->map[ctd++]) != (size_t)map->cols)
			freemap(map, "Map must be rectangular", 1);
}

void	check_map(t_map *map)
{
	int	ctd;
	int	ctd2;
	int	player;
	int	exit;

	ctd = -1;
	player = 0;
	exit = 0;
	while (map->map[++ctd])
	{
		ctd2 = -1;
		while (map->map[ctd][++ctd2])
		{
			if (ft_strchr(LEGAL_CHARS, map->map[ctd][ctd2]) == NULL)
				freemap(map, "Invalid character in map", 1);
			if (map->map[ctd][ctd2] == 'P')
				player++;
			else if (map->map[ctd][ctd2] == 'E')
				exit++;
		}
	}
	if (player != 1)
		freemap(map, "Invalid number of players", 1);
	if (exit != 1)
		freemap(map, "Invalid number of exits", 1);
}

void	read_map(t_map *map, int count, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
		read_map(map, count + 1, fd);
	else
	{
		if (count == 0)
			error_message("Empty file");
		map->map = malloc(sizeof(char *) * (count + 1));
		if (map->map == NULL)
			error_message("Error allocating memory");
		map->rows = count;
	}
	if (line)
	{
		map->map[count] = ft_strtrim(line, "\n");
		free(line);
	}
	else
		map->map[count] = NULL;
}

void	freemap(t_map *map, char *str, int status)
{
	int	ctd;

	ctd = 0;
	while (map->map[ctd])
		free(map->map[ctd++]);
	free(map->map);
	if (status == 1)
		error_message(str);
}

void	read_input(int argc, char **argv, t_map *map)
{
	int	input_len;
	int	fd;

	if (argc != 2)
		error_message("Invalid number of arguments");
	input_len = ft_strlen(argv[1]);
	if (input_len < 5 || ft_strncmp(argv[1] + input_len - 4, ".ber", 4) != 0)
		error_message("Invalid file, must be a .ber file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Error opening file");
	read_map(map, 0, fd);
	close(fd);
	validate_map(map);
}
