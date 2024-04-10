/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:48 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 02:47:39 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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
	end_routine(philo, table);
	return (true);
}

void	*philo_routine(t_philos *philo)
{
	bool		first;

	first = true;
	while (philo->info.number_eat != 0 && philo->table->simstatus)
	{
		if (first == true && !sync_philos(philo))
			break ;
		else
			first = false;
		if (!philo_eat(philo))
			break ;
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
	}
	free_table(philo->table);
	lst_clear(&philo);
	return (NULL);
}

bool	philo_eat(t_philos *philo)
{
	bool	sim_status;

	sim_status = philo->table->sim_status;
	if (!sim_status)
		return (false);
	get_forks(philo);
	print_message(philo, "is eating");
	philo->last_meal = get_time();
	usleep(philo->info.time_eat * 1000);
	relese_forks(philo);
	if (philo->info.number_eat != -1)
		philo->info.number_eat--;
	return (true);
}

bool	philo_sleep(t_philos *philo)
{
	bool	sim_status;

	sim_status = philo->table->sim_status;
	if (!sim_status)
		return (false);
	print_message(philo, "is sleeping");
	usleep(philo->info.time_sleep * 1000);
	return (true);
}

bool	philo_think(t_philos *philo)
{
	bool	sim_status;

	sim_status = philo->table->sim_status;
	if (!sim_status)
		return (false);
	print_message(philo, "is thinking");
	usleep(philo->info.time_think * 1000);
	return (true);
}
