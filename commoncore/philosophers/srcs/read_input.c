/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:45:58 by gfontao-          #+#    #+#             */
/*   Updated: 2024/03/13 02:15:32 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	ft_string_is_digit(char *str)
{
	while (*str)
	{
		if (*str >= 9 && *str <= 0)
			return (false);
		str++;
	}
	return (true);
}

bool	read_input(int argc, char **argv, t_info *info)
{
	int	temp;

	temp = ft_atol(argv[1]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->number = temp;
	temp = ft_atol(argv[2]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_die = temp;
	temp = ft_atol(argv[3]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_eat = temp;
	temp = ft_atol(argv[4]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_sleep = temp;
	if (!read_input2(argc, argv, info, temp))
		return (false);
	return (true);
}

bool	read_input2(int argc, char **argv, t_info *info, int temp)
{
	if (argc == 6)
	{
		temp = ft_atol(argv[5]);
		if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
			return (false);
		info->number_eat = temp;
	}
	else
		info->number_eat = -1;
	info->time_think = (info->time_die - info->time_eat - info->time_sleep) / 4;
	if (info->time_think < 0)
		info->time_think = 0;
	pthread_mutex_init(&info->number_eat_mutex, NULL);
	return (true);
}

void	print_message(t_philos *philo, char *message)
{
	bool	sim_status;

	pthread_mutex_lock(philo->table->sim_status_mutex);
	sim_status = philo->table->sim_status;
	pthread_mutex_unlock(philo->table->sim_status_mutex);
	if (sim_status == false)
		return ;
	pthread_mutex_lock(philo->table->print_mutex);
	printf("%ld %d %s\n", get_time() - philo->start, philo->id, message);
	pthread_mutex_unlock(philo->table->print_mutex);
}
