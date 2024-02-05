/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:13:24 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/25 11:55:02 by gfontao-         ###   ########.fr       */
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
