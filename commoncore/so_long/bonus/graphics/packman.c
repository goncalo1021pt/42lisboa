/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 14:10:28 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	find_start(t_mlx_start *par)
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
				par->packman->x = x * SCALE + BORDER;
				par->packman->y = y * SCALE + BORDER;
				par->map->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_addr(t_mlx_start *par)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		par->packman->img[i].addr = mlx_get_data_addr(par->packman->img[i].img,
				&par->packman->img[i].bits_per_pixel,
				&par->packman->img[i].line_length,
				&par->packman->img[i].endian);
		i++;
	}
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	static int	i = 0;
	int			direction;

	direction = 0;
	if (par->packman->dir == 'r' || par->packman->dir == 's')
		direction = 0;
	else if (par->packman->dir == 'd')
		direction = 4;
	else if (par->packman->dir == 'l')
		direction = 8;
	else if (par->packman->dir == 'u')
		direction = 12;
	i = choose_img(par, img, i, direction);
}

int	choose_img(t_mlx_start *par, t_img *img, int i, int direction)
{
	if (i < 10)
		create_img(img, par->packman->img[direction], par->packman->x,
			par->packman->y);
	else if (i < 20)
		create_img(img, par->packman->img[direction + 1], par->packman->x,
			par->packman->y);
	else if (i < 30)
		create_img(img, par->packman->img[direction + 2], par->packman->x,
			par->packman->y);
	else if (i < 39)
		create_img(img, par->packman->img[direction + 3], par->packman->x,
			par->packman->y);
	else
	{
		create_img(img, par->packman->img[direction + 3], par->packman->x,
			par->packman->y);
		i = -1;
	}
	i++;
	return (i);
}
