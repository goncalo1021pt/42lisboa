/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/04 17:38:25 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void find_start(t_mlx_start *par, t_packman *packman)
{
	int	x;
	int	y;

	y = 0;
	while (y < par->map->rows)
	{
		x = 0;
		while (x < par->map->cols)
		{
			if (par->map->map[y][x] == 'P')
			{
				packman->x = x * SCALE + BORDER;
				packman->y = y * SCALE + BORDER;
				par->map->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}


void	packman_init(t_mlx_start *par, t_packman *packman)
{
	find_start(par, packman);
	packman->img = mlx_xpm_file_to_image(par->mlx, "./textures/packman_1.xpm", &packman->width, &packman->height);
	if (packman->img == NULL)
		error_message("Error\nInvalid packman texture\n");
}
