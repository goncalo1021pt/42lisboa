/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/06 11:37:57 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	packman_init(t_mlx_start *par)
{
	par->packman = malloc(sizeof(t_packman));
	if (par->packman == NULL)
		error_message("Error\nMalloc failed\n");
	find_start(par);
	par->packman->img.img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_1.xpm", &par->packman->img.width, &par->packman->img.height);
	par->packman->img.addr = mlx_get_data_addr(par->packman->img.img, &par->packman->img.bits_per_pixel, &par->packman->img.line_length, &par->packman->img.endian);
	if (par->packman->img.img == NULL)
		error_message("Error\nInvalid packman texture\n");
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	create_img(img, par->packman->img, par->packman->x, par->packman->y);
}
