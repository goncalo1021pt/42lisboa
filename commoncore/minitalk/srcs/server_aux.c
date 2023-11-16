/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:17 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/15 22:42:37 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handler(int signum)
{
	static int	ascii = 0;
	static int	count = 0;

	if (signum == SIGUSR1)
		ascii += ft_pow(2, 7 - count);
	count++;
	if (count == 8)
	{
		if (ascii == 0)
		{
			ft_printf("\n");
			exit(0);
		}
		ft_printf("%c", ascii);
		ascii = 0;
		count = 0;
	}
}