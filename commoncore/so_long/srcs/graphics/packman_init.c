/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:20:18 by gfontao-          #+#    #+#             */
/*   Updated: 2025/01/21 16:32:47 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	packman_init(t_mlx_start *par)
{
	par->packman = malloc(sizeof(t_packman));
	if (par->packman == NULL)
		error_message("Error\nMalloc failed\n");
	find_start(par);
	par->packman->dir = 's';
	par->packman->next = 's';
	par->packman->prev = 's';
	par->packman->moves = 0;
	par->packman->img[0].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_0.xpm", &par->packman->img[0].width,
			&par->packman->img[0].height);
	get_addr(par);
}
