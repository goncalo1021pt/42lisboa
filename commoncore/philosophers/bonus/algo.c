/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 11:53:44 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

static bool	kill_all(t_philos *philo)
{
	t_philos	*start;

	start = philo;
	while (philo)
	{
		kill(philo->pid, SIGKILL);
		philo = philo->next;
		if (philo == start)
			break ;
	}
	return (true);
}

void	*simstatus_routine(void *lst)
{
	t_philos	*philo;
	long		last_meal;

	philo = (t_philos *)lst;
	while (1)
	{
		if (philo->info.number_eat == 0)
			break ;
		last_meal = philo->last_meal;
		if (last_meal + philo->info.time_die < get_time())
		{
			print_message(philo, "has died");
			sem_post(philo->table->simstatus);
		}
		usleep(1000);
	}
	return (NULL);
}

void	*kill_routine(void *list)
{
	t_table		*table;
	t_philos	*philo;

	table = (t_table *)list;
	philo = table->philo;
	sem_wait(philo->table->simstatus);
	if (table->sim_status == false)
		return (NULL);
	kill_all(philo);
	return (NULL);
}

bool	start_routine(t_philos *philo)
{
	t_philos	*start;
	pthread_t	simstatus;
	pthread_t	dead;

	start = philo;
	while (philo)
	{
		philo->pid = fork();
		if (philo->pid == 0)
		{
			pthread_create(&simstatus, NULL, simstatus_routine, philo);
			pthread_detach(simstatus);
			philo_routine(philo);
			exit(0);
		}
		else if (philo->pid < 0)
			return (kill_all(philo), false);
		philo = philo->next;
		if (philo == start)
			break ;
	}
	pthread_create(&dead, NULL, kill_routine, philo->table);
	pthread_detach(dead);
	return (true);
}

void	end_routine(t_philos *philo, t_table *table)
{
	t_philos	*start;

	start = philo;
	while (philo)
	{
		waitpid(philo->pid, NULL, 0);
		philo = philo->next;
		if (philo == start)
			break ;
	}
	table->sim_status = false;
	sem_post(philo->table->simstatus);
	usleep(1000);
	lst_clear(&philo);
}
