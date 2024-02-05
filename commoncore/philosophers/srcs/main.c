/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:40:20 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/05 23:37:44 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_info		info;
	t_philos	*philo;
	
	if (argc < 5 || argc > 6 || !read_input(argc, argv, &info) )
		return (printf("Error: invalid input\n"), 1);
	if (!philo_init(philo, &info))
		return (printf("Error: failed to initialize philosophers\n"), 1);
	
	return (0);
}