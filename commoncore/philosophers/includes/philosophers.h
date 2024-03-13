/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:42 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/13 11:35:51 by goncalo1021      ###   ########.fr       */
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
# define EVEN 0
# define ODD 1
# define SYNCHRONIZE 1000

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_info
{
	int					number;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	long				time_think;
	long				number_eat;
	t_mutex				number_eat_mutex;
}						t_info;

typedef struct s_philos
{
	int					id;
	long				last_meal;
	long				start;
	t_info				info;
	t_mutex				forks;
	t_mutex				last_meal_mutex;
	pthread_t			philo;
	t_table				*table;
	struct s_philos		*next;
}						t_philos;

struct					s_table
{
	t_philos			*philo;
	t_mutex				*print_mutex;
	t_mutex				*sim_status_mutex;
	bool				sim_status;
};

// parser
bool					read_input(int argc, char **argv, t_info *info);
bool					read_input2(int argc, char **argv, t_info *info,
							int temp);
void					print_message(t_philos *philo, char *message);

// lists
t_philos				*lst_new(int id, t_info info);
void					lst_add_back(t_philos **lst, t_philos *new);
void					lst_clear(t_philos **lst);

// utils
long					ft_atol(char *str);
void					*ft_calloc(size_t nmemb, size_t size);
bool					is_in_array(char *str, char c);
long					get_time(void);

// philos
bool					philo_init(t_table *table, t_info info);
void					*philo_routine(void *list);
bool					philo_eat(t_philos *philo);
bool					philo_sleep(t_philos *philo);
bool					philo_think(t_philos *philo);

// algo
bool					start_routine(t_philos *philo);
void					end_routine(t_philos *philo);
void					lock_forks(t_philos *philo);
void					unlock_forks(t_philos *philo);
void					check_status(t_table *table, t_philos *philo);
// table
bool					table_init(t_table *table);
void					free_table(t_table *table);
void					*stupid_case(t_philos *philo);
void					join_all(t_philos *list);

#endif