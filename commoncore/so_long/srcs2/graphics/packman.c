/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/11 20:31:16 by gfontao-         ###   ########.fr       */
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
	par->packman->moves = 0;
	par->packman->img[0].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_0.xpm", &par->packman->img[0].width, &par->packman->img[0].height);
	par->packman->img[1].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_1.xpm", &par->packman->img[1].width, &par->packman->img[1].height);
	par->packman->img[2].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_2.xpm", &par->packman->img[2].width, &par->packman->img[2].height);
	par->packman->img[3].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_3.xpm", &par->packman->img[3].width, &par->packman->img[3].height);
	par->packman->img[4].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_4.xpm", &par->packman->img[4].width, &par->packman->img[4].height);
	par->packman->img[5].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_5.xpm", &par->packman->img[5].width, &par->packman->img[5].height);
	par->packman->img[6].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_6.xpm", &par->packman->img[6].width, &par->packman->img[6].height);
	par->packman->img[7].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_7.xpm", &par->packman->img[7].width, &par->packman->img[7].height);
	par->packman->img[8].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_8.xpm", &par->packman->img[8].width, &par->packman->img[8].height);
	par->packman->img[9].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_9.xpm", &par->packman->img[9].width, &par->packman->img[9].height);
	par->packman->img[10].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_10.xpm", &par->packman->img[10].width, &par->packman->img[10].height);
	par->packman->img[11].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_11.xpm", &par->packman->img[11].width, &par->packman->img[11].height);
	par->packman->img[12].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_12.xpm", &par->packman->img[12].width, &par->packman->img[12].height);
	par->packman->img[13].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_13.xpm", &par->packman->img[13].width, &par->packman->img[13].height);
	par->packman->img[14].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_14.xpm", &par->packman->img[14].width, &par->packman->img[14].height);
	par->packman->img[15].img = mlx_xpm_file_to_image(par->mlx, "./includes/textures/packman_15.xpm", &par->packman->img[15].width, &par->packman->img[15].height);
	get_addr(par);
}

void get_addr(t_mlx_start *par)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		par->packman->img[i].addr = mlx_get_data_addr(par->packman->img[i].img, &par->packman->img[i].bits_per_pixel, &par->packman->img[i].line_length, &par->packman->img[i].endian);
		i++;
	}
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	static int	i = 0;
	int			direction;

	if (par->packman->dir == 'r' || par->packman->dir == 's')
		direction = 0;
	else if (par->packman->dir == 'd')
		direction = 4;
	else if (par->packman->dir == 'l')
		direction = 8;
	else if (par->packman->dir == 'u')
		direction = 12;
	if (i < 10)
		create_img(img, par->packman->img[direction], par->packman->x, par->packman->y);
	else if (i < 20)
		create_img(img, par->packman->img[direction + 1], par->packman->x, par->packman->y);
	else if (i < 30)
		create_img(img, par->packman->img[direction + 2], par->packman->x, par->packman->y);
	else if (i < 39)
		create_img(img, par->packman->img[direction + 3], par->packman->x, par->packman->y);
	else
	{
		create_img(img, par->packman->img[direction + 3], par->packman->x, par->packman->y);
		i = -1;
	}
	i++;
}
