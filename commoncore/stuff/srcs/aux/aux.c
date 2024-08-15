#include "../../includes/headers/cub3d.h"

bool	is_in_array(char *arr, char c)
{
	while (*arr)
	{
		if (c == *arr)
			return (true);
		arr++;
	}
	return (false);
}

bool	is_number(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
	{
		if (!ft_isdigit(str[ctd]))
			return (false);
		ctd++;
	}
	return (true);
}

int	ft_strslen(char **strs)
{
	int	ctd;

	ctd = 0;
	while (strs[ctd])
		ctd++;
	return (ctd);
}

int	get_hexa_color(char *color)
{
	char	**rgb;
	int		color_value[3];

	rgb = ft_split(color, ',');
	if (!rgb)
		return (ft_putendl_fd(ERR_ALLOC, 2), -1);
	color_value[0] = ft_atoi(rgb[0]);
	color_value[1] = ft_atoi(rgb[1]);
	color_value[2] = ft_atoi(rgb[2]);
	free_file(rgb);
	return (color_value[0] << 16 | color_value[1] << 8 | color_value[2]);
}

void	free_prev(char **arr_str, int ctd)
{
	while (ctd >= 0)
	{
		free(arr_str[ctd]);
		ctd--;
	}
	free(arr_str);
}
