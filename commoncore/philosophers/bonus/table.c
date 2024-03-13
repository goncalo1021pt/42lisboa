/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:40:07 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 02:38:51 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	init_sem(t_table *table)
{
	sem_unlink(SEM_FORKS);
	table->forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644, table->info.number);
	if (table->forks == SEM_FAILED)
		return (false);
	sem_unlink(SEM_PRINT);
	table->print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	if (table->print == SEM_FAILED)
		return (false);
	sem_unlink(SEM_SIMSTATUS);
	table->simstatus = sem_open(SEM_SIMSTATUS, O_CREAT | O_EXCL, 0644, 0);
	if (table->simstatus == SEM_FAILED)
		return (false);
	return (true);
}

bool	table_init(t_table *table, t_info info)
{
	table->info = info;
	init_sem(table);
	table->sim_status = true;
	table->philo = NULL;
	return (true);
}

void	free_table(t_table *table)
{
	sem_close(table->forks);
	sem_unlink(SEM_FORKS);
	sem_close(table->print);
	sem_unlink(SEM_PRINT);
	sem_close(table->simstatus);
	sem_unlink(SEM_SIMSTATUS);
}
