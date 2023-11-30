/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 16:35:37 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_mlx_start *par)
{
	mlx_destroy_window(par->mlx, par->mlx_win);
	freemap(par->map, NULL, 0);
	return (0);
}

int	key_hook(int keycode, t_mlx_start *par)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(par->mlx, par->mlx_win);
		freemap(par->map, NULL, 0);
	}
	printf("x = %d\n", par->packman->x);
	if (keycode == 'a')
		par->packman->x -= 10;
	if (keycode == 'd')
		par->packman->x += 10;
	if (keycode == 'w')
		par->packman->y -= 10;
	if (keycode == 's')
		par->packman->y += 10;
	mlx_clear_window(par->mlx, par->mlx_win);
	mlx_put_image_to_window(par->mlx, par->mlx_win, par->packman->img, par->packman->x, par->packman->y);
	return (0);
}
