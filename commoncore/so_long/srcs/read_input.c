/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:39 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/27 17:42:01 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* t_bool	check_line(char *line)
{
	int			ctd;
	static int	player;
	static int	exit;

	ctd = 0;
	while (line[ctd])
	{
		if (ft_strchr(LEGAL_CHARS, line[ctd]) == NULL)
			return (FALSE);
		if (line[ctd] == 'P')
			player++;
		else if (line[ctd] == 'E')
			exit++;
		ctd++;
	}
	return ((player != 1 || exit != 1));
} */

t_bool check_map(t_map *map)
{
	int	ctd;
	int ctd2;
	int	player;
	int	exit;

	ctd = 0;
	ctd2 = 0;
	player = 0;
	exit = 0;
	while (map->map[ctd])
	{
		while (map->map[ctd][ctd2])
		{
			if (ft_strchr(LEGAL_CHARS, map->map[][ctd]) == NULL)
				return (FALSE);
			if (map->map[ctd][ctd2] == 'P')
				player++;
			else if (map->map[ctd][ctd2] == 'E')
				exit++;
			ctd2++;
		}
		ctd++;
	}
	return ((player != 1 || exit != 1));
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
