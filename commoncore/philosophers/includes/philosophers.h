/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:42 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/05 23:31:05 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <string.h>
# define SPACE_LIST " \n\v\t\r\f"

typedef pthread_mutex_t t_mutex;

typedef struct s_info
{
	int number;
	int time_die;
	int	time_eat;
	int time_sleep;
	int	number_eat;
	t_mutex *status_mutex;
} t_info;


typedef struct s_philos
{
	int				id;
	t_info			info;
	t_mutex			forks;

	struct s_philos	*next;
} t_philos;

typedef struct s_table
{
	t_philos	*philo;
	t_mutex		*print;
	t_mutex		*dead;
} t_table;

// typedef struct s_philo_data
// {
// 	pthread_t		*philo;
// 	pthread_mutex_t	*print;
// 	pthread_mutex_t	*dead;
// } t_philo_data;

// parser
bool	read_input(int argc, char **argv, t_info *info);


// lists
t_philos *lst_new(int id, t_info *info);
void	lst_add_back(t_philos **lst, t_philos *new);
void	lst_clear(t_philos **lst);

// utils
long	ft_atol(char *str);
bool	ft_string_is_digit(char *str);
bool	is_in_array(char *str, char c);

// philos
bool philo_init(t_philos *philo, t_info *info);
#endif