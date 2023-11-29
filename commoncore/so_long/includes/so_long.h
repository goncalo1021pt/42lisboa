/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:34:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/29 13:30:10 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define LEGAL_CHARS "01CEP"
# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;

typedef struct s_mlx_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}	t_mlx_data;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	t_bool	**visited;
}	t_map;

typedef struct s_packman
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_packman;

typedef struct s_mlx_start
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	int			img_width;
	int			img_height;
}	t_mlx_start;


// so_long
void	print_map(t_map *map);

// close_program
void	error_message(char *str);
void	freemap(t_map *map, char *str, int status);

// read_input
void	check_line(t_map *map);
void	check_map(t_map *map);
void	read_map(t_map *map, int count, int fd);
void	read_input(int argc, char **argv, t_map *map);

// verify_map
t_bool	allocate_matrix(t_map *map);
void	free_matrix(t_map *map, int i, int max);
t_bool	flood_fill(t_map *map, int x, int y);
void	validate_map(t_map *map);

// graphics

// mlx_start
void	mlx_start(t_map *map);

// hooks
int		key_hook(int keycode, t_mlx_start *par);
int		close_window(t_mlx_start *par);

//packman
void	packman_init(t_mlx_start *par, t_packman *packman);

#endif
