/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/20 14:53:31 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool	move_packman(t_mlx_start *par, char direction, int status)
{
	int	x;
	int	y;

	x = par->packman->x;
	y = par->packman->y;
	if (direction == 'a' && par->map->map[(par->packman->y - BORDER)
			/ SCALE][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0
			|| par->map->map[(par->packman->y - BORDER) / SCALE
				+ 1][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
			par->packman->x -= MOVE_SPEED;
	if (direction == 'd' && par->map->map[(par->packman->y - BORDER)
			/ SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0
			|| par->map->map[(par->packman->y - BORDER) / SCALE
				+ 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->x += MOVE_SPEED;
	vertical_move(par, direction);
	return (check_map_state(par, status, x, y));
}

void	vertical_move(t_mlx_start *par, char direction)
{
	if (direction == 'w' && par->map->map[(par->packman->y - MOVE_SPEED
				- BORDER) / SCALE][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0
			|| par->map->map[(par->packman->y - MOVE_SPEED - BORDER)
				/ SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y -= MOVE_SPEED;
	if (direction == 's' && par->map->map[(par->packman->y - BORDER) / SCALE
			+ 1][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0
			|| par->map->map[(par->packman->y - BORDER) / SCALE
				+ 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y += MOVE_SPEED;
}

t_bool	check_map_state(t_mlx_start *par, int status, int x, int y)
{
	t_bool				flag;
	static long long	last_time = 0;

	flag = FALSE;
	if (x != par->packman->x || y != par->packman->y)
	{
		if (status == 0 && par->packman->dir != par->packman->next)
			par->packman->moves++;
		if (status == 0)
			par->packman->dir = par->packman->next;
		par->packman->prev = par->packman->dir;
		check_collectables(par);
		while (check_time(&last_time) == FALSE)
			;
		create_all(par, par->load_img);
		flag = TRUE;
	}
	else
		par->packman->dir = par->packman->prev;
	return (flag);
}

t_bool	check_time(long long *last_time)
{
	struct timeval	tv;
	long long		current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	if (current_time - *last_time >= FRAME_TIME)
	{
		*last_time = current_time;
		return (TRUE);
	}
	else
		return (FALSE);
}
