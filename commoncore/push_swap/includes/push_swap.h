/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:16:51 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/14 10:25:16 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_list_data
{
	t_stack	*head;
	t_stack	*tail;
}	t_list_data;

t_stack	*ft_lstnew(int content);
void	ft_dbl_lstadd_front(t_list_data **stack, t_stack *new);
void	ft_dbl_lstadd_back(t_list_data **stack, t_stack *new);
t_stack	*ft_dbl_rem_front(t_list_data **stack);
t_stack	*ft_dbl_rem_back(t_list_data **stack);

#endif