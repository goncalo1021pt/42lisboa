/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:34:40 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/17 18:58:10 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>

# define LEGAL_CHARS "01CEP"
# define TRUE 1
# define FALSE 0
# define SCALE 50
# define BORDER 50
# define MOVE_SPEED 2
# define TRANSPARENT 0xFF000000
# define WALL_COLOR 0x1100FE
#define FPS 60
#define FRAME_TIME (1000000 / FPS)

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
	int		ghosts;
}	t_check;

typedef struct s_map
{
	char	**map;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
	t_img	boarder_vertical;
	t_img	boarder_horizontal;
	int		rows;
	int		cols;
	int		collectibles_count;
	t_check	check;
	t_bool	**visited;
}	t_map;

typedef struct s_packman
{
	t_img	img[16];
	char	*path;
	char	dir;
	char	prev;
	char	next;
	int		x;
	int		y;
	int		moves;
}	t_packman;

typedef struct s_ghost
{
	t_img	img[4];
	char	*path;
	char	dir;
	int		x;
	int		y;
}	t_ghost;

typedef struct s_mlx_start
{
	void		*mlx;
	t_img		*load_img;
	int			width;
	int			height;
	void		*mlx_win;
	t_map		*map;
	t_packman	*packman;
	t_ghost		*ghost[4];
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

//check_map
void	check_map(t_map *map);
void map_verefications(t_map *map);

// verify_map
t_bool	allocate_visited(t_map *map);
void	initialize_visited(t_map *map);
void	free_matrix(t_map *map, int i, int max);
t_bool	flood_fill(t_map *map, int x, int y);
void	validate_map(t_map *map);

// graphics_new

// mlx_start
void	mlx_start(t_map *map);
int		mlx_exit(t_mlx_start *par, char *message, int status);
void	create_all(t_mlx_start *par, t_img *img);

// img
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		put_screen(t_mlx_start *par, t_img *img);
void	initialize_image(t_mlx_start *par, t_img *img, int width, int height);
void	create_img(t_img *img, t_img src, int x, int y);

//packman_init
void	packman_init(t_mlx_start *par);
void	packman_init2(t_mlx_start *par);
void	packman_init3(t_mlx_start *par);

// packman
void	find_start(t_mlx_start *par);
void	get_addr(t_mlx_start *par);
void	render_packman(t_mlx_start *par, t_img *img);
int		choose_img(t_mlx_start *par, t_img *img, int i, int direction);

//map_init
void	wall_init(t_mlx_start *par);
void	floor_init(t_mlx_start *par);
void	exit_init(t_mlx_start *par);
void	collectible_init(t_mlx_start *par);
void	boarder_init(t_mlx_start *par);
void	map_init(t_mlx_start *par);

// map
void	render_map(t_mlx_start *par, t_img *img);
void	render_map_condition(t_mlx_start *par, t_img *img, int x, int y);
void	render_boarder(t_mlx_start *par, t_img *img);
void	create_boarder(t_mlx_start *par, t_img *img, int x, int y);
void	render_counter(t_mlx_start *par);
void	pixel_fix(t_img *img, int x, int y);

// hooks
int		key_hook(int keycode, t_mlx_start *par);
t_bool	move_packman(t_mlx_start *par, char direction, int status);
void	vertical_move(t_mlx_start *par, char direction);
t_bool check_map_state(t_mlx_start *par, int status, int x, int y);

// hooks2
void	check_collectables(t_mlx_start *par);
int		const_move(t_mlx_start *par);
t_bool check_time(long long *last_time);

#endif
