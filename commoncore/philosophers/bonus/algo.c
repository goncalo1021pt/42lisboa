/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/12 18:27:22 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	start_routine(t_philos *philo)
{
	t_philos	*start;

	start = philo;
	while (philo)
	{
		philo->pid = fork();
		if (philo->pid == 0)
		{
			philo_routine(philo);
			exit(0);
		}
		else if (philo->pid < 0)
			return (false);
		philo = philo->next;
		if (philo == start)
			break;
	}
	return (true);	
}

void	end_routine(t_philos *philo)
{
	while (philo)
	{
		waitpid(philo->pid, NULL, 0);
		philo = philo->next;
	}
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

void	check_status(t_table *table, t_philos *philo)
{
	(void) table;
	(void) philo;
}
