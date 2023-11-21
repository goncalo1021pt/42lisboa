/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:34:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/21 17:18:41 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;

typedef struct s_mlx_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_params
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_mlx_data	img;
	size_t	x;
	size_t	y;
}	t_params;


void	testmlx(void);

#endif
