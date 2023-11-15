/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/15 16:38:47 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

t_bool check_input(char *input, int *pid)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (FALSE);
		i++;
	}
	*pid = ft_atoi(input);
	if (*pid < 0)
		return (FALSE);
	return (TRUE);
}

void send_signal(pid_t pid, char *str)
{
}
