/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 22:54:59 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	wall(t_mlx_start *par)
{
	par->map->wall = mlx_xpm_file_to_image(par->mlx, "./textures/wall.xpm", &par->map->rows, &par->map->cols);
	if (par->map->wall == NULL)
		error_message("Error\nInvalid wall texture\n");
}

void	floor(t_mlx_start *par)
{
	par->map->floor = mlx_xpm_file_to_image(par->mlx, "./textures/floor.xpm", &par->map->rows, &par->map->cols);
	if (par->map->floor == NULL)
		error_message("Error\nInvalid floor texture\n");
}

void	render_map(t_mlx_start *par)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	par->map->map;
	while (par->map->map[y])
	{
		while (par->map->map[y][x])
		{
			if (par->map->map[y][x] == '1')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->wall, (x * 50) + 50, (y * 50) + 50);
			else if (par->map->map[y][x] == '0')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->floor, (x * 50) + 50, (y * 50) + 50);
			else if (par->map->map[y][x] == 'C')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->collectible, (x * 50) + 50, (y * 50) + 50);
			else if (par->map->map[y][x] == 'E')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->exit, (x * 50) + 50, (y * 50) + 50);
			x++;
		}
		x = 0;
		y++;
	}
}
