/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 15:07:47 by gfontao-         ###   ########.fr       */
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
	par->packman->img[0].addr = mlx_get_data_addr(par->packman->img[0].img,
			&par->packman->img[0].bits_per_pixel,
			&par->packman->img[0].line_length,
			&par->packman->img[0].endian);
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	create_img(img, par->packman->img[0], par->packman->x, par->packman->y);
}
