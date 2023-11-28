/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/28 15:43:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->cols * 64, map->rows * 64, "so_long");
}

void mlx_start()
{
	t_params	params;
	int			x;
	int			y;
	params.mlx = mlx_init();
	params.mlx_win = mlx_new_window(params.mlx, 2400,1080, "so_long");
	params.img.img = mlx_new_image(params.mlx, 2400, 1080);
	params.img.addr = mlx_get_data_addr(params.img.img, &params.img.bits_per_pixel, &params.img.line_length, &params.img.endian);

	mlx_put_image_to_window(params.mlx, params.mlx_win, params.img.img, 0, 0);

	mlx_loop(params.mlx);
}
