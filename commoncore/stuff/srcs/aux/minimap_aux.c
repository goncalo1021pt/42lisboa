#include "../../includes/headers/cub3d.h"

int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

size_t	max_len(char **split)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (split[i])
	{
		if (ft_strlen(split[i]) > max)
			max = ft_strlen(split[i]);
		i++;
	}
	return (max);
}
