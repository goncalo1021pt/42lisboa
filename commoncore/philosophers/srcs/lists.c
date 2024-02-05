/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:45 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/05 23:33:00 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philos *lst_new(int id, t_info *info)
{
	t_philos *new;

	new = (t_philos *)malloc(sizeof(t_philos));
	if (!new)
		return (NULL);
	new->info = *info;
	new->id = id;
	pthread_mutex_init(&new->forks, NULL);
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_philos **lst, t_philos *new)
{
	static t_philos *end;

	if (!lst)
		return ;
	if (end)
		end->next = new;
	else
		*lst = new;
	end = new;
}

void	lst_clear(t_philos **lst)
{
	t_philos *temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		pthread_mutex_destroy(&(*lst)->forks);
		free(*lst);
		*lst = temp;
	}
}
