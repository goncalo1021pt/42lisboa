/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:12:05 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/03 21:12:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd, int total)
{
	char	c;

	if ((n / 10) > 0)
	{
		ft_putunbr_fd(n / 10, fd, total++);
		ft_putunbr_fd(n % 10, fd, total++);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	return total;
}
