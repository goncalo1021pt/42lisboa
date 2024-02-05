/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:45:58 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/05 13:22:28 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool ft_string_is_digit(char *str)
{
	while (*str)
	{
		if (*str >= 9 && *str <= 0)
			return (false);
		str++;
	}
	return (true);
}

bool   read_input(int argc, char **argv, t_info *info)
{
	int temp;
	if (argc < 5 || argc > 6)
		return (false);
	temp = ft_atol(argv[1]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->number = temp;	
	temp = ft_atol(argv[2]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_die = temp;
	temp = ft_atol(argv[3] || ft_strlen(argv[3]) > 10);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_eat = temp;
	temp = ft_atol(argv[4]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_sleep = temp;
	temp = ft_atol(argv[5]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->number_eat = temp;
	if (argc == 5)
		info->number_eat = -1;
	return (true);
}
