/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:35:24 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/22 18:33:43 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int	main(int argc,char **argv)
{
	t_map	map;

	read_input(argc, argv, &map);
	print_map(&map);

	freemap(&map, NULL, 0);
	return (0);
}
