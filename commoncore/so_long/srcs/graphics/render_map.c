/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/30 19:15:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	wall_init(t_mlx_start *par)
{
	par->map->wall = mlx_xpm_file_to_image(par->mlx, "./textures/wall.xpm", &par->map->rows, &par->map->cols);
	if (par->map->wall == NULL)
		error_message("Error\nInvalid wall texture\n");
}

void	floor_init(t_mlx_start *par)
{
	par->map->floor = mlx_xpm_file_to_image(par->mlx, "./textures/floor.xpm", &par->map->rows, &par->map->cols);
	if (par->map->floor == NULL)
		error_message("Error\nInvalid floor texture\n");
}

void exit_init(t_mlx_start *par)
{
	par->map->exit = mlx_xpm_file_to_image(par->mlx, "./textures/exit.xpm", &par->map->rows, &par->map->cols);
	if (par->map->exit == NULL)
		error_message("Error\nInvalid exit texture\n");
}

void collectible_init(t_mlx_start *par)
{
	par->map->collectible = mlx_xpm_file_to_image(par->mlx, "./textures/collectible.xpm", &par->map->rows, &par->map->cols);
	if (par->map->collectible == NULL)
		error_message("Error\nInvalid collectible texture\n");
}

void	render_map(t_mlx_start *par)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	wall_init(par);
	floor_init(par);
	exit_init(par);
	collectible_init(par);
	while (par->map->map[y])
	{
		while (par->map->map[y][x])
		{
			if (par->map->map[y][x] == '1')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->wall, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == '0')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->floor, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == 'C')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->collectible, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == 'E')
				mlx_put_image_to_window(par->mlx, par->mlx_win, par->map->exit, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			x++;
		}
		x = 0;
		y++;
	}
}
