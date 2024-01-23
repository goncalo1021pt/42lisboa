/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/10 12:39:27 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
			render_map_condition(par, img, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_condition(t_mlx_start *par, t_img *img, int x, int y)
{
	if (par->map->map[y][x] == '1')
	{
		create_img(img, par->map->wall, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	}
	else if (par->map->map[y][x] == '0')
		create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'C')
		create_img(img, par->map->collectible, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'E' && par->map->collectibles_count == 0)
		create_img(img, par->map->exit, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'E')
		create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
}

void	render_boarder(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	(void)img;
	y = 0;
	while (y < par->map->rows)
	{
		x = 0;
		while (x < par->map->cols)
		{
			if (par->map->map[y][x] == '1')
				create_boarder(par, img, x, y);
			x++;
		}
		y++;
	}
}

void	create_boarder(t_mlx_start *par, t_img *img, int x, int y)
{
	if (x + 1 < par->map->cols && par->map->map[y][x + 1] == '1')
	{
		if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1'
			&& par->map->map[y + 1][x + 1] == '1')
			pixel_fix(img, x, y);
		create_img(img, par->map->boarder_vertical, ((x + 1) * SCALE) + BORDER
			- 1, (y * SCALE) + BORDER + 1);
	}
	if (x - 1 >= 0 && par->map->map[y][x - 1] == '1')
		create_img(img, par->map->boarder_vertical, (x * SCALE) + BORDER, (y
				* SCALE) + BORDER + 1);
	if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1,
			((y + 1) * SCALE) + BORDER - 1);
	if (y - 1 >= 0 && par->map->map[y - 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1,
			(y * SCALE) + BORDER);
}

void	pixel_fix(t_img *img, int x, int y)
{
	put_pixel(img, ((x + 1) * SCALE) + BORDER - 1, ((y + 1) * SCALE) + BORDER
		- 1, WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER, ((y + 1) * SCALE) + BORDER - 1,
		WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER - 1, ((y + 1) * SCALE) + BORDER,
		WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER, ((y + 1) * SCALE) + BORDER,
		WALL_COLOR);
}
