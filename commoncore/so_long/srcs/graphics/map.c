/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/08 01:02:42 by gfontao-         ###   ########.fr       */
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

void boarder_init(t_mlx_start *par)
{
	par->map->boarder_vertical.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/boarder_vertical.xpm", &par->map->boarder_vertical.width, &par->map->boarder_vertical.height);
	if (par->map->boarder_vertical.img == NULL)
		error_message("Error\nInvalid boarder texture\n");
	par->map->boarder_vertical.addr = mlx_get_data_addr(par->map->boarder_vertical.img, &par->map->boarder_vertical.bits_per_pixel, &par->map->boarder_vertical.line_length, &par->map->boarder_vertical.endian);
	par->map->boarder_horizontal.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/boarder_horizontal.xpm", &par->map->boarder_horizontal.width, &par->map->boarder_horizontal.height);
	if (par->map->boarder_horizontal.img == NULL)
		error_message("Error\nInvalid boarder texture\n");
	par->map->boarder_horizontal.addr = mlx_get_data_addr(par->map->boarder_horizontal.img, &par->map->boarder_horizontal.bits_per_pixel, &par->map->boarder_horizontal.line_length, &par->map->boarder_horizontal.endian);
}

void	render_map(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (par->map->map[y])
	{
		x = 0;
		while (par->map->map[y][x])
		{
			if (par->map->map[y][x] == '1'){
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
		}
		y++;
	}
}

void render_boarder(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < par->map->rows)
	{
		x = 0;
		while (x < par->map->cols)
		{
			if ((par->map->map[y][x] == '1'))
				create_boarder(par, img, x, y);
			x++;
		}
		y++;
	}
}

void create_boarder(t_mlx_start *par, t_img *img, int x, int y)
{
	if (x + 1 < par->map->cols && par->map->map[y][x + 1] == '1' )
	{
		if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1' && par->map->map[y + 1][x + 1] == '1')
		{
			put_pixel(img, ((x + 1)* SCALE) + BORDER - 1 , ((y + 1) * SCALE) + BORDER - 1, WALL_COLOR);
			put_pixel(img, ((x + 1)* SCALE) + BORDER , ((y + 1) * SCALE) + BORDER - 1, WALL_COLOR);
			put_pixel(img, ((x + 1)* SCALE) + BORDER - 1 , ((y + 1) * SCALE) + BORDER, WALL_COLOR);
			put_pixel(img, ((x + 1)* SCALE) + BORDER , ((y + 1) * SCALE) + BORDER, WALL_COLOR);
		}
		create_img(img, par->map->boarder_vertical, ((x + 1)* SCALE) + BORDER - 1 , (y * SCALE) + BORDER + 1);
	}
	if (x - 1 >= 0 && par->map->map[y][x - 1] == '1')
		create_img(img, par->map->boarder_vertical, (x * SCALE) + BORDER , (y * SCALE) + BORDER + 1);
	if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1 , ((y + 1) * SCALE) + BORDER - 1);
	if (y - 1 >= 0 && par->map->map[y - 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1 , (y * SCALE) + BORDER);
}

void	map_init(t_mlx_start *par)
{
	wall_init(par);
	floor_init(par);
	exit_init(par);
	collectible_init(par);
	boarder_init(par);
}
