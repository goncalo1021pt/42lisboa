/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/07 14:35:49 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mlx_exit(t_mlx_start *par, char *message, int status)
{
	mlx_destroy_image(par->mlx, par->load_img->img);
	mlx_destroy_image(par->mlx, par->map->wall.img);
	mlx_destroy_image(par->mlx, par->map->floor.img);
	mlx_destroy_image(par->mlx, par->map->collectible.img);
	mlx_destroy_image(par->mlx, par->map->exit.img);
	mlx_destroy_image(par->mlx, par->map->boarder_vertical.img);
	mlx_destroy_image(par->mlx, par->map->boarder_horizontal.img);
	mlx_destroy_image(par->mlx, par->packman->img.img);
	mlx_destroy_window(par->mlx, par->mlx_win);
	mlx_destroy_display(par->mlx);
	free(par->packman);
	free(par->mlx);
	freemap(par->map, message, status);
	return (0);
}

void	create_all(t_mlx_start *par, t_img *img)
{
	render_map(par, img);
	render_packman(par, img);
	put_screen(par, img);
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_img		img;
	int			width;
	int			height;

	width = map->cols * SCALE + BORDER * 2;
	height = map->rows * SCALE + BORDER * 2;
	par.map = map;
	par.mlx = mlx_init();
	par.mlx_win = mlx_new_window(par.mlx, width, height, "So_Long");
	initialize_image(&par, &img, width, height);
	packman_init(&par);
	map_init(&par);
	create_all(&par, &img);
	mlx_hook(par.mlx_win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 1L << 17, mlx_exit, &par);
	mlx_loop(par.mlx);
}
