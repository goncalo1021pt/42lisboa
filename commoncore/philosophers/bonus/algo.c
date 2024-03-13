/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 02:53:11 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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
	t_philos	*start;

	table = (t_table *)list;
	philo = table->philo;
	start = philo;
	sem_wait(philo->table->simstatus);
	printf("table->sim_status: %d\n", table->sim_status);
	if (table->sim_status == false)
		return (NULL);
	while (philo)
	{
		kill(philo->pid, SIGKILL);
		philo = philo->next;
		if (philo == start)
			break ;
	}
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
			return (false);
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

void	get_forks(t_philos *philo)
{
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
}

void	relese_forks(t_philos *philo)
{
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}

bool	sync_philos(t_philos *philo)
{
	if (philo->info.number == 1)
		return (usleep(philo->info.time_die * 1000), false);
	if ((philo->id % 2 == 0 || philo->next->id == 1))
	{
		usleep(1000);
		if (philo->next->id == 1)
			usleep(1000);
	}
	return (true);
}
