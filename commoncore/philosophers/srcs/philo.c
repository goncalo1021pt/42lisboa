/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:48 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/05 23:42:44 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	philo_init(t_philos *philo, t_info *info)
{
	int ctd;
	t_philos *temp;
	
	ctd = 0;
	while (ctd < info->number)
	{
		temp = lst_new(ctd + 1, info);
		if (!temp)
			return (lst_clear(&philo), false);
		lst_add_back(&philo, temp);
		ctd++;
	}
	return (true);
}

void	*philo_routine(t_philos *philo)
{
	while (philo->info.number)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philos *philo);

void	philo_sleep(t_philos *philo);

void	philo_think(t_philos *philo);