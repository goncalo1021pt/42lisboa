/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/05 18:04:22 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mlx_exit(t_mlx_start *par, char *message, int status)
{
	freemap(par->map, message, status);
	return (0);
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_img		img;

	par.map = map;
	par.mlx = mlx_init();
	par.mlx_win = mlx_new_window(par.mlx, 1920, 1080, "So_Long");
	initialize_image(&par, &img);
	packman_init(&par);
	create_img(&img, par.packman->img, par.packman->x, par.packman->y);

	mlx_loop(par.mlx);
}
