/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:35:24 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:05 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	print_map(t_map *map)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (map->map[ctd])
	{
		ctd2 = 0;
		while (map->map[ctd][ctd2])
		{
			ft_printf("%c", map->map[ctd][ctd2]);
			ctd2++;
		}
		ft_printf("\n");
		ctd++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	read_input(argc, argv, &map);
	freemap(&map, NULL, 0);
	return (0);
}
