/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:39 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/23 13:45:45 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool check_line(char *line)
{
	int ctd;

	ctd = 0;
	while (line[ctd])
	{
		if (line[ctd] == '\n')
			line[ctd] = '\0';
		if (ft_strchr(LEGAL_CHARS, line[ctd]) == NULL)
			return (FALSE);
		ctd++;
	}
	return (TRUE);
}

void read_map(t_map *map, int count, int fd)
{
	char *line;

	line = get_next_line(fd);
	if (line != NULL)
		read_map(map, count + 1, fd);
	else
	{
		if(count == 0)
			error_message("Empty file");
		map->map = malloc(sizeof(char *) * (count + 1));
		if (map->map == NULL)
			error_message("Error allocating memory");
	}
	if (line)
		map->map[count] = line;
}

void freemap(t_map *map, char *str, int status)
{
	int	ctd;

	ctd = 0;
	while (map->map[ctd])
	{
		free(map->map[ctd]);
		ctd++;
	}
	free(map->map);
	if (status == 1)
		error_message(str);
}

void validate_map(t_map *map)
{
	int				ctd;
	int				ctd2;
	unsigned int	line_len;
	unsigned int	line_len2;

	line_len = ft_strlen(map->map[0]);
	ctd = 0;
	while (map->map[ctd])
	{
		ft_putstr_fd(map->map[ctd], 1);
		line_len2 = ft_strlen(map->map[ctd]);
		if ((ft_strlen(map->map[ctd]) != line_len && map->map[ctd][line_len2 - 1] == '\n')|| line_len < 3)
			freemap(map, "Map must be rectangular", 1);
		if (check_line(map->map[ctd]) == FALSE)
			freemap(map, "Invalid character in map", 1);
		ctd++;
	}
	ctd2 = 0;
	while (map->map[0][ctd2])
	{
		if (map->map[0][ctd2] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (map->map[ctd - 1][ctd2])
	{
		if (map->map[ctd - 1][ctd2] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (map->map[ctd2][0])
	{
		if (map->map[ctd2][0] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
	ctd2 = 0;
	while (map->map[ctd2][ctd - 1])
	{
		if (map->map[ctd2][ctd - 1] != '1')
			freemap(map, "Map must be surrounded by walls", 1);
		ctd2++;
	}
}

void print_map(t_map *map)
{
	int ctd;
	int ctd2;

	ctd = 0;
	while (map->map[ctd])
	{
		ctd2 = 0;
		while (map->map[ctd][ctd2])
		{
			printf("%c", map->map[ctd][ctd2]);
			ctd2++;
		}
		ctd++;
	}
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
