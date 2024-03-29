/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:40:07 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 11:35:18 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	table_init(t_table *table)
{
	table->sim_status_mutex = ft_calloc(1, sizeof(t_mutex));
	if (!table->sim_status_mutex)
		return (false);
	pthread_mutex_init(table->sim_status_mutex, NULL);
	table->print_mutex = ft_calloc(1, sizeof(t_mutex));
	if (!table->print_mutex)
		return (free(table->sim_status_mutex), false);
	pthread_mutex_init(table->print_mutex, NULL);
	table->sim_status = true;
	table->philo = NULL;
	return (true);
}

void	free_table(t_table *table)
{
	pthread_mutex_destroy(table->sim_status_mutex);
	pthread_mutex_destroy(table->print_mutex);
	free(table->sim_status_mutex);
	free(table->print_mutex);
}

void	*stupid_case(t_philos *philo)
{
	pthread_mutex_lock(&philo->forks);
	print_message(philo, "has taken a fork");
	usleep(philo->info.time_die * 1000);
	pthread_mutex_unlock(&philo->forks);
	return (NULL);
}

void	join_all(t_philos *list)
{
	t_philos	*start;

	start = list;
	while (list)
	{
		if (list->philo)
			pthread_join(list->philo, NULL);
		list = list->next;
		if (list == start)
			break ;
	}
}
