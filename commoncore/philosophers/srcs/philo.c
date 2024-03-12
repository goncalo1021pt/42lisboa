/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:48 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/11 19:44:38 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	philo_init(t_table *table, t_info info)
{
	int			ctd;
	t_philos	*philo;
	t_philos	*temp;
	long		start;

	ctd = 0;
	philo = NULL;
	start = get_time();
	while (ctd < info.number)
	{
		temp = lst_new(ctd + 1, info);
		temp->table = table;
		temp->start = start;
		if (!temp)
			return (lst_clear(&philo), false);
		lst_add_back(&philo, temp);
		if (ctd == 0)
			table->philo = philo;
		ctd++;
	}
	if (!start_routine(philo))
		return (false);
	check_status(table, philo);
	end_routine(philo);
	return (true);
}

void	*philo_routine(void *list)
{
	t_philos	*philo;
	bool		first;

	philo = (t_philos *)list;
	first = true;
	if (philo->info.number == 1)
		return (print_message(philo, "has taken a fork"),
			usleep(philo->info.time_die * 1000), NULL);
	while (philo->info.number_eat != 0)
	{
		if ((philo->id % 2 == 0 || philo->next->id == 1) && first == true)
		{
			usleep(SYNCHRONIZE);
			if (philo->next->id == 1)
				usleep(SYNCHRONIZE);
			first = false;
		}
		if (!philo_eat(philo))
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

bool	philo_eat(t_philos *philo)
{
	bool	sim_status;

	pthread_mutex_lock(philo->table->sim_status_mutex);
	sim_status = philo->table->sim_status;
	pthread_mutex_unlock(philo->table->sim_status_mutex);
	if (!sim_status)
		return (false);
	lock_forks(philo);
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	usleep(philo->info.time_eat * 1000);
	unlock_forks(philo);
	if (philo->info.number_eat != -1)
	{
		pthread_mutex_lock(&philo->info.number_eat_mutex);
		philo->info.number_eat--;
		pthread_mutex_unlock(&philo->info.number_eat_mutex);
	}
	return (true);
}

bool	philo_sleep(t_philos *philo)
{
	bool	sim_status;

	pthread_mutex_lock(philo->table->sim_status_mutex);
	sim_status = philo->table->sim_status;
	pthread_mutex_unlock(philo->table->sim_status_mutex);
	if (!sim_status)
		return (false);
	print_message(philo, "is sleeping");
	usleep(philo->info.time_sleep * 1000);
	return (true);
}

bool	philo_think(t_philos *philo)
{
	bool	sim_status;

	pthread_mutex_lock(philo->table->sim_status_mutex);
	sim_status = philo->table->sim_status;
	pthread_mutex_unlock(philo->table->sim_status_mutex);
	if (!sim_status)
		return (false);
	print_message(philo, "is thinking");
	usleep(philo->info.time_think * 1000);
	return (true);
}
