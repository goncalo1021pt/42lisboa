/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/11 16:06:54 by gfontao-         ###   ########.fr       */
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
	par->packman->dir = 's';
	par->packman->next = 's';
	par->packman->prev = 's';
	par->packman->img[0].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_0.xpm", &par->packman->img[0].width, &par->packman->img[0].height);
	par->packman->img[1].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_1.xpm", &par->packman->img[1].width, &par->packman->img[1].height);
	par->packman->img[2].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_2.xpm", &par->packman->img[2].width, &par->packman->img[2].height);
	par->packman->img[3].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_3.xpm", &par->packman->img[3].width, &par->packman->img[3].height);
	par->packman->img[0].addr = mlx_get_data_addr(par->packman->img[0].img, &par->packman->img[0].bits_per_pixel, &par->packman->img[0].line_length, &par->packman->img[0].endian);
	par->packman->img[1].addr = mlx_get_data_addr(par->packman->img[1].img, &par->packman->img[1].bits_per_pixel, &par->packman->img[1].line_length, &par->packman->img[1].endian);
	par->packman->img[2].addr = mlx_get_data_addr(par->packman->img[2].img, &par->packman->img[2].bits_per_pixel, &par->packman->img[2].line_length, &par->packman->img[2].endian);
	par->packman->img[3].addr = mlx_get_data_addr(par->packman->img[3].img, &par->packman->img[3].bits_per_pixel, &par->packman->img[3].line_length, &par->packman->img[3].endian);
	if (par->packman->img[0].img == NULL || par->packman->img[1].img == NULL || par->packman->img[2].img == NULL || par->packman->img[3].img == NULL)
		error_message("Error\nInvalid packman texture\n");
	packman_rotate(par);
}

void rotate_img(t_img *src, t_img *dst)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < src->width)
	{
		y = 0;
		while (y < src->height)
		{
			color = get_pixel(src, x, y);
			put_pixel(dst, y, src->width - x - 1, color);
			y++;
		}
		x++;
	}
}

void	packman_rotate(t_mlx_start *par)
{
	int	ctd;

	ctd = 4;
	while (ctd < 16)
	{
		par->packman->img[ctd].img = mlx_new_image(par->mlx, par->packman->img[ctd - 4].width, par->packman->img[ctd - 4].height);
		par->packman->img[ctd].addr = mlx_get_data_addr(par->packman->img[ctd].img, &par->packman->img[ctd].bits_per_pixel, &par->packman->img[ctd].line_length, &par->packman->img[ctd].endian);
		rotate_img(&par->packman->img[ctd - 4], &par->packman->img[ctd]);
	}
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	static int	i = 0;
	int			direction;

	if (par->packman->dir == 'r')
		direction = 0;
	else if (par->packman->dir == 'u')
		direction = 4;
	else if (par->packman->dir == 'l')
		direction = 8;
	else if (par->packman->dir == 'd')
		direction = 12;
	if (i < 10)
		create_img(img, par->packman->img[direction], par->packman->x, par->packman->y);
	else if (i < 20)
		create_img(img, par->packman->img[direction + 1], par->packman->x, par->packman->y);
	else if (i < 30)
		create_img(img, par->packman->img[direction + 2], par->packman->x, par->packman->y);
	else if (i < 40)
		create_img(img, par->packman->img[direction + 3], par->packman->x, par->packman->y);
	else
		i = -1;
	i++;
}
