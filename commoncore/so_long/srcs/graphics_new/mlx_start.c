/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/06 12:05:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mlx_exit(t_mlx_start *par, char *message, int status)
{
	freemap(par->map, message, status);
	return (0);
}

void	create_all(t_mlx_start *par, t_img *img)
{
	ft_printf("test 2\n");
	render_map(par, img);
	ft_printf("test 3\n");
	render_packman(par, img);
	ft_printf("test 4\n");
	put_screen(par, img);
	ft_printf("test 5\n");
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
	map_init(&par);
	create_all(&par, &img);
	mlx_hook(par.mlx_win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 1L << 17, mlx_exit, &par);

	mlx_loop(par.mlx);
}
