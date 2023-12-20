/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:13:24 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 14:23:44 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	map_init(t_mlx_start *par)
{
	wall_init(par);
	floor_init(par);
	exit_init(par);
	collectible_init(par);
	boarder_init(par);
}

void	render_counter(t_mlx_start *par)
{
	char	*moves;
	int		pos_x;

	pos_x = 25;
	moves = ft_itoa(par->packman->moves);
	if (ft_strlen(moves) == 2)
		pos_x -= 5;
	else if (ft_strlen(moves) == 3)
		pos_x -= 10;
	else if (ft_strlen(moves) == 4)
		pos_x -= 15;
	mlx_string_put(par->mlx, par->mlx_win, pos_x, 30, 0x00FFFFFF, moves);
	free(moves);
}
