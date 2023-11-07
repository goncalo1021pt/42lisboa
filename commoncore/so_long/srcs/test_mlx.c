/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:50:54 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/07 15:21:09 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	testmlx(void)
{
	void		*mlx;
	void		*mlx_win;
	int 		x;
	int			y;
	t_mlx_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2400, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 2400, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	x = 400;
	while (x < 600)
	{
		y = 300;
		while (y < 500)
		{
			my_mlx_pixel_put(&img, x, y, 0x009900);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
