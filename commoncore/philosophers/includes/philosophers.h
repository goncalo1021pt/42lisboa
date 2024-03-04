/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:42 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/22 14:50:20 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# define SPACE_LIST " \n\v\t\r\f"

typedef pthread_mutex_t	t_mutex;
typedef struct s_table t_table;

typedef struct s_info
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_eat;
	t_mutex			*status_mutex;
}						t_info;

typedef struct s_philos
{
	int				id;
	long			last_meal;
	t_info			info;
	t_mutex			forks;
	pthread_t		philo;
	t_table			*table;
	struct s_philos	*next;
}						t_philos;

struct s_table
{
	t_philos		*philo;
	t_mutex			*print;
	t_mutex			*dead;

	// bool			dead;
	// t_mutex			table;
} ;

// parser
bool				read_input(int argc, char **argv, t_info *info);
void				print_message(t_philos *philo, char *message);

// lists
t_philos			*lst_new(int id, t_info info);
void				lst_add_back(t_philos **lst, t_philos *new);
void				lst_clear(t_philos **lst);

// utils
long				ft_atol(char *str);
bool				ft_string_is_digit(char *str);
bool				is_in_array(char *str, char c);
long				get_time(void);

// philos
bool				philo_init(t_info info);
void				*philo_routine(void *list);
void				philo_eat(t_philos *philo);
void				philo_sleep(t_philos *philo);
void				philo_think(t_philos *philo);


#endif