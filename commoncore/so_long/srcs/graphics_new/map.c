/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/06 12:22:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	wall_init(t_mlx_start *par)
{
	par->map->wall.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/wall.xpm", &par->map->wall.width, &par->map->wall.height);
	if (par->map->wall.img == NULL)
		error_message("Error\nInvalid wall texture\n");
	par->map->wall.addr = mlx_get_data_addr(par->map->wall.img, &par->map->wall.bits_per_pixel, &par->map->wall.line_length, &par->map->wall.endian);
}

void	floor_init(t_mlx_start *par)
{
	par->map->floor.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/floor.xpm", &par->map->floor.width, &par->map->floor.height);
	if (par->map->floor.img == NULL)
		error_message("Error\nInvalid floor texture\n");
	par->map->floor.addr = mlx_get_data_addr(par->map->floor.img, &par->map->floor.bits_per_pixel, &par->map->floor.line_length, &par->map->floor.endian);
}

void	exit_init(t_mlx_start *par)
{
	par->map->exit.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/exit.xpm", &par->map->exit.width, &par->map->exit.height);
	if (par->map->exit.img == NULL)
		error_message("Error\nInvalid exit texture\n");
	par->map->exit.addr = mlx_get_data_addr(par->map->exit.img, &par->map->exit.bits_per_pixel, &par->map->exit.line_length, &par->map->exit.endian);
}

void	collectible_init(t_mlx_start *par)
{
	par->map->collectible.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/collectible.xpm", &par->map->collectible.width, &par->map->collectible.height);
	if (par->map->collectible.img == NULL)
		error_message("Error\nInvalid collectible texture\n");
	par->map->collectible.addr = mlx_get_data_addr(par->map->collectible.img, &par->map->collectible.bits_per_pixel, &par->map->collectible.line_length, &par->map->collectible.endian);
}

void	render_map(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	ft_printf("test 2-1\n");
	while (par->map->map[y])
	{
		x = 0;
		ft_printf("test 2-2\n");
		while (par->map->map[y][x])
		{
			ft_printf("test 2-3\n");
			if (par->map->map[y][x] == '1'){
				ft_printf("test 2-3-1\n");
				create_img(img, par->map->wall, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			}
			else if (par->map->map[y][x] == '0')
				create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == 'C')
				create_img(img, par->map->collectible, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == 'E' && par->map->collectibles_count == 0)
				create_img(img, par->map->exit, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			else if (par->map->map[y][x] == 'E')
				create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE) + BORDER);
			x++;
			ft_printf("test 2-4\n");
		}
		y++;
	}
}

void	map_init(t_mlx_start *par)
{
	wall_init(par);
	floor_init(par);
	exit_init(par);
	collectible_init(par);
}
