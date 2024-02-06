#include "../includes/philosophers.h"

bool philo_init(t_philos **philo, t_info info)
{
	t_philos *tmp;
	int ctd;
	
	ctd = 0;
	while (ctd < info.number)
	{
		tmp = lst_new(ctd);
		if (!tmp)
			return (lst_clear(*philo), false);
		lst_add_back(philo, tmp);
		(*philo)->info = info;
		ctd++;
	}
	
}