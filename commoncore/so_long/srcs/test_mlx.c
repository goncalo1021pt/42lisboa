/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:50:54 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/21 18:01:56 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	put_screen(t_params *params)
{
	mlx_clear_window(params->mlx, params->mlx_win);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img.img, params->x, params->y);
	return (0);
}

int	key_hook(int keycode, t_params *params)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(params->mlx, params->mlx_win);
		exit(0);
	}
	if (keycode == 'a')
		params->x -= 10;
	if (keycode == 'd')
		params->x += 10;
	if (keycode == 'w')
		params->y -= 10;
	if (keycode == 's')
		params->y += 10;
	return (0);
}

void	testmlx(void)
{
	void		*mlx;
	int 		x;
	int			y;
	t_mlx_data	img;
	t_params	params;


	mlx = mlx_init();
	params.mlx_win = mlx_new_window(mlx, 2400, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 2400, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	params.mlx = mlx;
	params.img = img;
	params.x = 0;
	params.y = 0;


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
	mlx_put_image_to_window(mlx, params.mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx, put_screen, &params);
	mlx_loop(mlx);
}
