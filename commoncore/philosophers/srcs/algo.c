/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:51 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/04 11:59:31 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_routine(t_philos *philo)
{
	while (philo)
	{
		if (pthread_create(&philo->philo, NULL, philo_routine, philo))
			return (lst_clear(&philo), false);
		philo = philo->next;
	}
}

void end_routine(t_philos *philo)
{
	while (philo)
	{
		pthread_join(philo->philo, NULL);
		philo = philo->next;
	}
	lst_clear(&philo);
}
