/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:16:51 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/15 12:47:23 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

t_stack	*ft_dbl_new(int content);
void	ft_dbl_add_front(t_list_data *stack, t_stack *new);
void	ft_dbl_add_back(t_list_data *stack, t_stack *new);
t_stack	*ft_dbl_rem_front(t_list_data *stack);
t_stack	*ft_dbl_rem_back(t_list_data *stack);
void	ft_swap_01(t_list_data *stack);
void	ft_rotate(t_list_data *stack);
void	ft_rev_rotate(t_list_data *stack); 
void	ft_dlb_print(t_list_data *stack);
void	ft_dbl_clear(t_list_data *stack);
int		save_stack(char **input, t_stack *stack_a);

#endif