#include "../includes/philosophers.h"

t_philos *lst_new(int id)
{
	t_philos *new;

	new = (t_philos *)malloc(sizeof(t_philos));
	if (!new)
		return (NULL);
	new->id = id;
	pthread_mutex_init(&new->right, NULL);
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
