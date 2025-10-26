/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2025/01/21 16:34:03 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	mlx_exit(t_mlx_start *par, char *message, int status)
{
	mlx_destroy_image(par->mlx, par->packman->img[0].img);
	mlx_destroy_image(par->mlx, par->load_img->img);
	mlx_destroy_image(par->mlx, par->map->wall.img);
	mlx_destroy_image(par->mlx, par->map->floor.img);
	mlx_destroy_image(par->mlx, par->map->collectible.img);
	mlx_destroy_image(par->mlx, par->map->exit.img);
	mlx_destroy_image(par->mlx, par->map->boarder_vertical.img);
	mlx_destroy_image(par->mlx, par->map->boarder_horizontal.img);
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
	render_boarder(par, img);
	render_packman(par, img);
	put_screen(par, img);
}

void	mlx_initiazie_var(t_mlx_start *par, t_map *map)
{
	int	width;
	int	height;

	par->map = map;
	par->width = map->cols * SCALE + BORDER * 2;
	par->height = map->rows * SCALE + BORDER * 2;
	par->mlx = mlx_init();
	mlx_get_screen_size(par->mlx, &width, &height);
	par->mlx_win = mlx_new_window(par->mlx, par->width, par->height, "So_Long");
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_img		img;

	mlx_initiazie_var(&par, map);
	initialize_image(&par, &img, par.width, par.height);
	packman_init(&par);
	map_init(&par);
	create_all(&par, &img);
	mlx_loop_hook(par.mlx, const_move, &par);
	mlx_hook(par.mlx_win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 1L << 17, mlx_exit, &par);
	mlx_loop(par.mlx);
}
