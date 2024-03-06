/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/05 17:30:05 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	start_routine(t_philos *philo)
{
	t_philos *first;

	first = philo;
	while (philo)
	{
		if (pthread_create(&philo->philo, NULL, philo_routine, philo))
			return (lst_clear(&philo), false);
		philo = philo->next;
		if (philo == first)
			break;
	}
	return (true);
}

void end_routine(t_philos *philo)
{
	t_philos *first;
	
	first = philo;
	while (philo)
	{
		pthread_join(philo->philo, NULL);
		philo = philo->next;
		if (philo == first)
			break;
	}
	lst_clear(&philo);
}
