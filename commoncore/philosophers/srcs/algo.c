/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 11:33:54 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	start_routine(t_philos *philo)
{
	t_philos	*first;

	first = philo;
	while (philo)
	{
		if (pthread_create(&philo->philo, NULL, philo_routine, philo))
		{
			pthread_mutex_lock(philo->table->sim_status_mutex);
			philo->table->sim_status = false;
			pthread_mutex_unlock(philo->table->sim_status_mutex);
			return (join_all(philo), lst_clear(&philo), false);
		}
		philo = philo->next;
		if (philo == first)
			break ;
	}
	return (true);
}

void	end_routine(t_philos *philo)
{
	t_philos	*first;

	first = philo;
	while (philo)
	{
		pthread_join(philo->philo, NULL);
		philo = philo->next;
		if (philo == first)
			break ;
	}
	lst_clear(&philo);
}

void	lock_forks(t_philos *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->forks);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->next->forks);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->next->forks);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks);
		print_message(philo, "has taken a fork");
	}
}

void	unlock_forks(t_philos *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(&philo->forks);
		pthread_mutex_unlock(&philo->next->forks);
	}
	else
	{
		pthread_mutex_unlock(&philo->next->forks);
		pthread_mutex_unlock(&philo->forks);
	}
}

void	check_status(t_table *table, t_philos *philo)
{
	long	last_meal;

	while (philo)
	{
		pthread_mutex_lock(&philo->info.number_eat_mutex);
		if (philo->info.number_eat == 0)
		{
			pthread_mutex_unlock(&philo->info.number_eat_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->info.number_eat_mutex);
		pthread_mutex_lock(&philo->last_meal_mutex);
		last_meal = philo->last_meal;
		pthread_mutex_unlock(&philo->last_meal_mutex);
		if (last_meal + philo->info.time_die < get_time())
		{
			print_message(philo, "has died");
			pthread_mutex_lock(table->sim_status_mutex);
			table->sim_status = false;
			pthread_mutex_unlock(table->sim_status_mutex);
			break ;
		}
		philo = philo->next;
	}
}
