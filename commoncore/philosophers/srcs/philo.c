/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:48 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/08 18:01:38 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	philo_init(t_info info)
{
	int ctd;
	t_philos *philo;
	t_philos *temp;
	
	ctd = 0;
	philo = NULL;
	while (ctd < info.number)
	{
		temp = lst_new(ctd + 1, info);
		if (!temp)
			return (lst_clear(&philo), false);
		lst_add_back(&philo, temp);
		ctd++;
	}
	temp = philo;
	while (temp)
	{
		if (!pthread_create(&temp->philo, NULL, philo_routine, temp))
			return (lst_clear(&philo), false);
		temp = temp->next;
	}
	return (true);
}

void	*philo_routine(void *list)
{
	t_philos *philo;

	philo = (t_philos *)list;
	while (philo->info.number)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->forks);
	pthread_mutex_lock(&philo->next->forks);
	philo->last_meal = get_time();
	usleep(philo->info.time_eat * 1000);
	pthread_mutex_unlock(&philo->forks);
	pthread_mutex_unlock(&philo->next->forks);	
	if (philo->info.number_eat != -1)
		philo->info.number_eat--;
	if (philo->info.number_eat == 0)
		philo->info.number = 0;
}

void	philo_sleep(t_philos *philo)
{
	print_message(philo, "is sleeping");
	usleep(philo->info.time_sleep * 1000);
}

void	philo_think(t_philos *philo)
{
	pthread_mutex_lock(philo->info.status_mutex);
	print_message(philo, "is thinking");
	pthread_mutex_unlock(philo->info.status_mutex);
}
