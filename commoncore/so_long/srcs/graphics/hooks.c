/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/30 15:14:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_mlx_start *par)
{
	mlx_destroy_window(par->mlx, par->mlx_win);
	freemap(par->map, NULL, 0);
	return (0);
}

void move_packman()
{
	
}

int	key_hook(int keycode, t_mlx_start *par)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(par->mlx, par->mlx_win);
		freemap(par->map, NULL, 0);
	}
	if (keycode == 'a')
		par->packman->x -= 10;
	if (keycode == 'd')
		par->packman->x += 10;
	if (keycode == 'w')
		par->packman->y -= 10;
	if (keycode == 's')
		par->packman->y += 10;
	else
		ft_printf("%i\n", keycode);
	put_image(par);
	return (0);
}
