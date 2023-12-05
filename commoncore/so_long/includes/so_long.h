/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:34:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/05 18:04:42 by gfontao-         ###   ########.fr       */
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
# define SCALE 50
# define BORDER 50
# define TRANSPARENT 0xFF000000

typedef unsigned char	t_bool;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_check
{
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		collectibles;
}	t_check;

typedef struct s_map
{
	char	**map;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	int		rows;
	int		cols;
	int		collectibles_count;
	t_check	check;
	t_bool	**visited;
}	t_map;

typedef struct s_packman
{
	t_img	img;
	char	*path;
	int		x;
	int		y;
	// int		width;
	// int		height;
}	t_packman;

typedef struct s_mlx_start
{
	void		*mlx;
	// void		*img;
	void		*mlx_win;
	// char		*addr;
	// int			line_length;
	// int			endian;
	// int			bits_per_pixel;
	t_map		*map;
	t_packman	*packman;
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
t_bool	allocate_visited(t_map *map);
void	initialize_visited(t_map *map);
void	free_matrix(t_map *map, int i, int max);
t_bool	flood_fill(t_map *map, int x, int y);
void	validate_map(t_map *map);

// graphics

// mlx_start
// void	put_image(t_mlx_start *par);
// void	mlx_start(t_map *map);
// int		mlx_exit(t_mlx_start *par, char *message , int status);

// hooks
// int		key_hook(int keycode, t_mlx_start *par);
// int		close_window(t_mlx_start *par);
// void	move_packman(t_mlx_start *par, char direction);
// void	check_collectables(t_mlx_start *par);

//packman
// void	packman_init(t_mlx_start *par, t_packman *packman);

// render_map
// void	wall_init(t_mlx_start *par);
// void	floor_init(t_mlx_start *par);
// void	exit_init(t_mlx_start *par);
// void	render_map(t_mlx_start *par);

// graphics_new
// mlx_start
void	mlx_start(t_map *map);
int		mlx_exit(t_mlx_start *par, char *message, int status);

// img
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		put_screen(t_mlx_start *par, t_img *img);
void	initialize_image(t_mlx_start *par, t_img *img);
void	create_img(t_img *img, t_img src, int x, int y);

// packman_init
void	find_start(t_mlx_start *par, t_packman *packman);
void	packman_init(t_mlx_start *par);

#endif
