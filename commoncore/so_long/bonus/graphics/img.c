/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:20:25 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/15 10:46:30 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	put_screen(t_mlx_start *par, t_img *img)
{
	mlx_clear_window(par->mlx, par->mlx_win);
	mlx_put_image_to_window(par->mlx, par->mlx_win, img->img, 0, 0);
	return (0);
}

void create_img (t_img *img, t_img src, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < src.width)
	{
		j = 0;
		while (j < src.height)
		{
			color = get_pixel(&src, i, j);
			if (color != TRANSPARENT)
				put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	initialize_image(t_mlx_start *par, t_img *img, int width, int height)
{
	img->img = mlx_new_image(par->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	par->load_img = img;
}
