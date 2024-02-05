/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:45:58 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/03 21:30:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_bool ft_string_is_digit(char *str)
{
	while (*str)
	{
		if (*str >= 9 && *str <= 0)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool   read_input(int argc, char **argv, t_info *info)
{
	int temp;
	if (argc < 5 || argc > 6)
		return (FALSE);
	temp = ft_atol(argv[1]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (FALSE);
	info->number = temp;	
	temp = ft_atol(argv[2]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (FALSE);
	info->time_die = temp;
	temp = ft_atol(argv[3] || ft_strlen(argv[3]) > 10);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (FALSE);
	info->time_eat = temp;
	temp = ft_atol(argv[4]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (FALSE);
	info->time_sleep = temp;
	temp = ft_atol(argv[5]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (FALSE);
	info->number_eat = temp;
	if (argc == 5)
		info->number_eat = -1;
	return (TRUE);
}
