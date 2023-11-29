/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 11:20:10 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	packman_init(t_mlx_start *par, t_packman *packman)
{
	packman->path = "../../textures/packman_1.xpm";
	packman->width = 64;
	packman->height = 64;
	packman->img = mlx_xpm_file_to_image(par->mlx, packman->path, &packman->width, &packman->height);
}
