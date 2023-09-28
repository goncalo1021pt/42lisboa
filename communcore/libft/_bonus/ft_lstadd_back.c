#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	i = *lst;
	while (i->next != NULL)
		i = i->next;
	i->next = new;
}

/* void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		ft_lstadd_back(&((*lst)->next), new);
	*lst = new;
} */
