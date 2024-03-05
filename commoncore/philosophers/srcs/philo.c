/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:48 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/05 11:49:31 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	philo_init(t_table *table, t_info info)
{
	int ctd;
	t_philos *philo;
	t_philos *temp;
	
	ctd = 0;
	philo = NULL;
	while (ctd < info.number)
	{
		temp = lst_new(ctd + 1, info);
		temp->table = table;
		if (!temp)
			return (lst_clear(&philo), false);
		lst_add_back(&philo, temp);
		if (ctd == 0)
			table->philo = philo;
		ctd++;
	}
	if (!start_routine(philo))
		return (false);
	end_routine(philo);
	return (true);
}

void	*philo_routine(void *list)
{
	t_philos *philo;

	philo = (t_philos *)list;
	while (philo->info.number_eat != 0)
	{
		// if (is_dead = true )
		// // 	break;
		// if (lfork && rfork)
		// 	eat;
		// else if (!lfork && !rfork)
		// 	try to eat;
		philo_eat(philo);
		// if (is_dead = true )
		// 	break;
		philo_sleep(philo);
		// if (is_dead = true )
		// 	break;
		philo_think(philo);
		// if (is_dead = true )
		// 	break;
	}
	return (NULL);
}

void	philo_eat(t_philos *philo)
{
	// pthread_mutex_lock(&philo->forks);
	// pthread_mutex_lock(&philo->next->forks);
	print_message(philo, "is eating");
	philo->last_meal = get_time();
	usleep(philo->info.time_eat * 1000);
	// pthread_mutex_unlock(&philo->forks);
	// pthread_mutex_unlock(&philo->next->forks);	
	if (philo->info.number_eat != -1)
		philo->info.number_eat--;
}

void	philo_sleep(t_philos *philo)
{
	print_message(philo, "is sleeping");
	usleep(philo->info.time_sleep * 1000);
}

void	philo_think(t_philos *philo)
{
	print_message(philo, "is thinking");
}
