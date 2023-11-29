/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 12:04:39 by gfontao-         ###   ########.fr       */
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
	return (0);
}
