/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/30 19:50:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_mlx_start *par)
{
	mlx_destroy_window(par->mlx, par->mlx_win);
	freemap(par->map, NULL, 0);
	return (0);
}

void move_packman(t_mlx_start *par, char direction)
{
	if (direction == 'a' && par->map->map[par->packman->y / SCALE][(par->packman->x - 10) / SCALE] != '1')
		par->packman->x -= 10;
	if (direction == 'd' && par->map->map[par->packman->y / SCALE][(par->packman->x + 10) / SCALE] != '1')
		par->packman->x += 10;
	if (direction == 'w' && par->map->map[(par->packman->y - 10) / SCALE][par->packman->x / SCALE] != '1')
		par->packman->y -= 10;
	if (direction == 's' && par->map->map[(par->packman->y + 10) / SCALE][par->packman->x / SCALE] != '1')
		par->packman->y += 10;
}

int	key_hook(int keycode, t_mlx_start *par)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(par->mlx, par->mlx_win);
		freemap(par->map, NULL, 0);
	}
	if (keycode == 'a')
		move_packman(par, 'a');
	if (keycode == 'd')
		move_packman(par, 'd');
	if (keycode == 'w')
		move_packman(par, 'w');
	if (keycode == 's')
		move_packman(par, 's');
	else
		ft_printf("%i\n", keycode);
	printf("x: %i\ny: %i\n", par->packman->x, par->packman->y);
	put_image(par);
	return (0);
}
