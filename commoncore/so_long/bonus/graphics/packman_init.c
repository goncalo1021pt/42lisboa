/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:20:18 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 14:10:46 by gfontao-         ###   ########.fr       */
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
	packman_init2(par);
	packman_init3(par);
	get_addr(par);
}

void	packman_init2(t_mlx_start *par)
{
	par->packman->img[0].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_0.xpm", &par->packman->img[0].width,
			&par->packman->img[0].height);
	par->packman->img[1].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_1.xpm", &par->packman->img[1].width,
			&par->packman->img[1].height);
	par->packman->img[2].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_2.xpm", &par->packman->img[2].width,
			&par->packman->img[2].height);
	par->packman->img[3].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_3.xpm", &par->packman->img[3].width,
			&par->packman->img[3].height);
	par->packman->img[4].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_4.xpm", &par->packman->img[4].width,
			&par->packman->img[4].height);
	par->packman->img[5].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_5.xpm", &par->packman->img[5].width,
			&par->packman->img[5].height);
	par->packman->img[6].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_6.xpm", &par->packman->img[6].width,
			&par->packman->img[6].height);
	par->packman->img[7].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_7.xpm", &par->packman->img[7].width,
			&par->packman->img[7].height);
}

void	packman_init3(t_mlx_start *par)
{
	par->packman->img[8].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_8.xpm", &par->packman->img[8].width,
			&par->packman->img[8].height);
	par->packman->img[9].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_9.xpm", &par->packman->img[9].width,
			&par->packman->img[9].height);
	par->packman->img[10].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_10.xpm", &par->packman->img[10].width,
			&par->packman->img[10].height);
	par->packman->img[11].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_11.xpm", &par->packman->img[11].width,
			&par->packman->img[11].height);
	par->packman->img[12].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_12.xpm", &par->packman->img[12].width,
			&par->packman->img[12].height);
	par->packman->img[13].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_13.xpm", &par->packman->img[13].width,
			&par->packman->img[13].height);
	par->packman->img[14].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_14.xpm", &par->packman->img[14].width,
			&par->packman->img[14].height);
	par->packman->img[15].img = mlx_xpm_file_to_image(par->mlx,
			"./includes/textures/packman_15.xpm", &par->packman->img[15].width,
			&par->packman->img[15].height);
}
