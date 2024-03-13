/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:40:20 by gfontao-          #+#    #+#             */
/*   Updated: 2024/03/13 01:14:36 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_table	table;

	if (argc < 5 || argc > 6 || !read_input(argc, argv, &info))
		return (printf("Error: invalid input\n"), 1);
	if (!table_init(&table, info) || !philo_init(&table, info))
		return (printf("Error: failed to initialize philosophers\n"), 1);
	else
		free_table(&table);
	return (0);
}
