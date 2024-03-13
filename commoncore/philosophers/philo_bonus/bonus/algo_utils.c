/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:23:38 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 11:36:06 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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
