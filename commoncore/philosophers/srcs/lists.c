/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:45 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 02:14:15 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philos	*lst_new(int id, t_info info)
{
	t_philos	*new;

	new = (t_philos *)malloc(sizeof(t_philos));
	if (!new)
		return (NULL);
	pthread_mutex_init(&new->forks, NULL);
	pthread_mutex_init(&new->last_meal_mutex, NULL);
	new->philo = 0;
	new->last_meal = get_time();
	new->info = info;
	new->id = id;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_philos **lst, t_philos *new)
{
	static t_philos	*end;

	if (!lst)
		return ;
	if (end)
	{
		end->next = new;
		new->next = *lst;
	}
	else
	{
		*lst = new;
		new->next = *lst;
	}
	end = new;
}

void	lst_clear(t_philos **lst)
{
	t_philos	*temp;
	t_philos	*first;

	if (!lst)
		return ;
	first = *lst;
	while (*lst)
	{
		temp = (*lst)->next;
		pthread_mutex_destroy(&(*lst)->forks);
		pthread_mutex_destroy(&(*lst)->last_meal_mutex);
		free(*lst);
		*lst = temp;
		if (*lst == first)
			break ;
	}
}
