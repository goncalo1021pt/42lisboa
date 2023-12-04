/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:34 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void put_image(t_mlx_start *par)
{
	mlx_clear_window(par->mlx, par->mlx_win);
	render_map(par);
	mlx_put_image_to_window(par->mlx, par->mlx_win, par->packman->img, par->packman->x, par->packman->y);
}



int mlx_exit(t_mlx_start *par, char *message , int status)
{
	mlx_destroy_image(par->mlx, par->img);
	mlx_destroy_window(par->mlx, par->mlx_win);
	mlx_destroy_display(par->mlx);
	freemap(par->map, message, status);
	return (0);
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_packman	packman;

	par.map = map;
	par.mlx = mlx_init();
	par.mlx_win = mlx_new_window(par.mlx, 1920, 1080, "So_Long");
	// par.img = mlx_new_image(par.mlx, 1920, 1080);
	// par.addr = mlx_get_data_addr(par.img, &par.bits_per_pixel, &par.line_length, &par.endian);
	packman_init(&par, &packman);
	par.packman = &packman;
	mlx_key_hook(par.mlx_win, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 0, close_window, &par);
	mlx_loop(par.mlx);
}
