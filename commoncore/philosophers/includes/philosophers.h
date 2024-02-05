#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
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
	t_mutex			right;

	struct s_philos	*next;
} t_philos;

// typedef struct s_philo_data
// {
// 	pthread_t		*philo;
// 	pthread_mutex_t	*print;
// 	pthread_mutex_t	*dead;
// } t_philo_data;

long ft_atol(char *str);

#endif