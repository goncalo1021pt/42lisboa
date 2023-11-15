/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:01:41 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/14 14:01:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker(t_stack *stack_a, t_stack *stack_b);
t_list	*get_moves(void);
t_bool	interpreter2(t_stack *stack_a, t_stack *stack_b, char *str);
t_bool	mutual_interpreter2(t_stack *stack_a, t_stack *stack_b, char *str);

#endif
