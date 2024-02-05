#include "../includes/philosophers.h"

t_philos *lst_new(int id, t_mutex *right)
{
	t_philos *new;

	new = (t_philos *)malloc(sizeof(t_philos));
	if (!new)
		return (NULL);
	new->id = id;
	new->right = right;
	new->next = NULL;
	return (new);
}