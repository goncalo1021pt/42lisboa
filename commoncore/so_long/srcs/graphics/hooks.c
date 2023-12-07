/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/07 12:00:19 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void move_packman(t_mlx_start *par, char direction)
{
	if (direction == 'a' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
			par->packman->x -= MOVE_SPEED;
	if (direction == 'd' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->x += MOVE_SPEED;
	if (direction == 'w' && par->map->map[(par->packman->y - MOVE_SPEED - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - MOVE_SPEED - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y -= MOVE_SPEED;
	if (direction == 's' && par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y += MOVE_SPEED;
	check_collectables(par);
	create_all(par, par->load_img);
}

void	check_collectables(t_mlx_start *par)
{
	int	x;
	int	y;

	x = (par->packman->x - BORDER) / SCALE;
	y = (par->packman->y - BORDER) / SCALE;
	if ((par->packman->y - BORDER) % SCALE != 0 || (par->packman->x - BORDER) % SCALE != 0)
		return ;
	if (par->map->map[y][x] == 'C')
	{
		par->map->map[y][x] = '0';
		par->map->collectibles_count--;
	}
	if (par->map->collectibles_count == 0 && par->map->map[y][x] == 'E')
	{
		ft_printf("You win!\n");
		mlx_exit(par, NULL, 0);
	}
}

int	key_hook(int keycode, t_mlx_start *par)
{
	if (keycode == 65307)
		mlx_exit(par, NULL, 0);
	if (keycode == 'a')
		move_packman(par, 'a');
	if (keycode == 'd')
		move_packman(par, 'd');
	if (keycode == 'w')
		move_packman(par, 'w');
	if (keycode == 's')
		move_packman(par, 's');

	return (0);
}
