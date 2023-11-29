/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 14:37:46 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_packman	packman;

	par.map = map;
	par.mlx = mlx_init();
	par.mlx_win = mlx_new_window(par.mlx, 1280, 720, "So_Long");
	packman_init(&par, &packman);
	mlx_put_image_to_window(par.mlx, par.mlx_win, packman.img, 200, 200);
	mlx_hook(par.mlx_win, 17, 0, close_window, &par);
	mlx_key_hook(par.mlx_win, key_hook, &par);
	//mlx_hook(par.mlx_win, 17, 1L << 17, key_hook, &par);


	mlx_loop(par.mlx);
}
