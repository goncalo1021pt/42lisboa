#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include "my_libft/libft.h"


typedef struct s_philos
{
	int number;
	int time_die;
	int	time_eat;
	int time_sleep;
	int	number_eat;
	
} t_philos;

typedef struct s_philo_data
{
	int				id;
	pthread_t		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
} t_philo_data;

#endif