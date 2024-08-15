#include "../../includes/headers/cub3d.h"

bool load_textures(t_session *ist)
{
	ist->textures[NORTH_TEXTURE].img = mlx_xpm_file_to_image(ist->mlx_ser, ist->map.no,&ist->textures[NORTH_TEXTURE].width, &ist->textures[NORTH_TEXTURE].height);
	ist->textures[SOUTH_TEXTURE].img = mlx_xpm_file_to_image(ist->mlx_ser, ist->map.so,&ist->textures[SOUTH_TEXTURE].width, &ist->textures[SOUTH_TEXTURE].height);
	ist->textures[WEST_TEXTURE].img = mlx_xpm_file_to_image(ist->mlx_ser, ist->map.we,&ist->textures[WEST_TEXTURE].width, &ist->textures[WEST_TEXTURE].height);
	ist->textures[EAST_TEXTURE].img = mlx_xpm_file_to_image(ist->mlx_ser, ist->map.ea,&ist->textures[EAST_TEXTURE].width, &ist->textures[EAST_TEXTURE].height);
	ist->textures[DOOR_TEXTURE_1].img = mlx_xpm_file_to_image(ist->mlx_ser, "./includes/assets/IMG_6.xpm",&ist->textures[DOOR_TEXTURE_1].width, &ist->textures[DOOR_TEXTURE_1].height);
	if (!ist->textures[NORTH_TEXTURE].img || !ist->textures[SOUTH_TEXTURE].img || !ist->textures[WEST_TEXTURE].img || !ist->textures[EAST_TEXTURE].img || !ist->textures[DOOR_TEXTURE_1].img)
		return (ft_putendl_fd(ERR_TEXTURE_LOAD, 2), false);
	ist->textures[NORTH_TEXTURE].addr = mlx_get_data_addr(ist->textures[NORTH_TEXTURE].img, &ist->textures[NORTH_TEXTURE].bpp, &ist->textures[NORTH_TEXTURE].line_length, &ist->textures[NORTH_TEXTURE].endian);
	ist->textures[SOUTH_TEXTURE].addr = mlx_get_data_addr(ist->textures[SOUTH_TEXTURE].img, &ist->textures[SOUTH_TEXTURE].bpp, &ist->textures[SOUTH_TEXTURE].line_length, &ist->textures[SOUTH_TEXTURE].endian);
	ist->textures[WEST_TEXTURE].addr = mlx_get_data_addr(ist->textures[WEST_TEXTURE].img, &ist->textures[WEST_TEXTURE].bpp, &ist->textures[WEST_TEXTURE].line_length, &ist->textures[WEST_TEXTURE].endian);
	ist->textures[EAST_TEXTURE].addr = mlx_get_data_addr(ist->textures[EAST_TEXTURE].img, &ist->textures[EAST_TEXTURE].bpp, &ist->textures[EAST_TEXTURE].line_length, &ist->textures[EAST_TEXTURE].endian);
	ist->textures[EAST_TEXTURE].addr = mlx_get_data_addr(ist->textures[EAST_TEXTURE].img, &ist->textures[EAST_TEXTURE].bpp, &ist->textures[EAST_TEXTURE].line_length, &ist->textures[EAST_TEXTURE].endian);
	ist->textures[DOOR_TEXTURE_1].addr = mlx_get_data_addr(ist->textures[DOOR_TEXTURE_1].img, &ist->textures[DOOR_TEXTURE_1].bpp, &ist->textures[DOOR_TEXTURE_1].line_length, &ist->textures[DOOR_TEXTURE_1].endian);
	return (true);
}
