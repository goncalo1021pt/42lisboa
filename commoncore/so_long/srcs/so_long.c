/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:35:24 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/04 12:54:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	mlx_start(&map);
	freemap(&map, NULL, 0);
	return (0);
}
