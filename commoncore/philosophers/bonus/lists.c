/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:45 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/12 11:38:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

t_philos	*lst_new(int id, t_info info)
{
	t_philos	*new;

	new = (t_philos *)malloc(sizeof(t_philos));
	if (!new)
		return (NULL);
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
		free(*lst);
		*lst = temp;
		if (*lst == first)
			break ;
	}
}
