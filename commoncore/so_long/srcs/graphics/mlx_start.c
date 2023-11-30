/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/30 19:14:59 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void put_image(t_mlx_start *par)
{
	mlx_clear_window(par->mlx, par->mlx_win);
	render_map(par);
	mlx_put_image_to_window(par->mlx, par->mlx_win, par->packman->img, par->packman->x, par->packman->y);
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_packman	packman;

	par.map = map;
	par.mlx = mlx_init();
	par.mlx_win = mlx_new_window(par.mlx, 2560, 1500, "So_Long");
	// par.img = mlx_new_image(par.mlx, 1280, 720);
	// par.addr = mlx_get_data_addr(par.img, &par.bits_per_pixel, &par.line_length, &par.endian);
	packman_init(&par, &packman);
	par.packman = &packman;
	mlx_key_hook(par.mlx_win, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 0, close_window, &par);
	mlx_loop(par.mlx);
}
