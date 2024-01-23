/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:45:58 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/03 13:21:25 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool   read_input(int argc, char **argv, t_philos *info)
{
	int temp;
	if (argc < 5 || argc > 6)
		return (false);
	temp = ft_atoi_long(argv[1]);
	if (temp < 1 || temp > INT_MAX || ft_strlen(argv[1]) > 10 || !ft_string_is_digit(argv[1]))
		return (false);
	info->number = temp;	
	temp = ft_atoi_long(argv[2]);
	if (temp > INT_MAX || ft_strlen(argv[2]) > 10 || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_die = temp;
	temp = ft_atoi_long(argv[3] || ft_strlen(argv[3]) > 10);
	if (temp > INT_MAX || ft_strlen(argv[3]) > 10 || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_eat = temp;
	temp = ft_atoi_long(argv[4]);
	if (temp > INT_MAX || ft_strlen(argv[4]) > 10 || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_sleep = temp;
	temp = ft_atoi_long(argv[5]);
	if (temp > INT_MAX || ft_strlen(argv[5]) > 10 || !ft_string_is_digit(argv[1]))
		return (false);
	info->number_eat = temp;
	if (argc == 5)
		info->number_eat = -1;
	return (true);
}
