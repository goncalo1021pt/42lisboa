#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == NULL)
		return ;
	ft_lstclear(&((*lst)->next), del);
	del((*lst)->content);
	free(*lst);
}

/* void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
} */
