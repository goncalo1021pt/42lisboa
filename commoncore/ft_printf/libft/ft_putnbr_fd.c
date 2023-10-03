/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:38:33 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/03 20:52:18 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd, int total)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			total++;
			write(fd, "-", 1);
		}
		if ((n / 10) > 0)
		{
			ft_putnbr_fd(n / 10, fd, total);
			ft_putnbr_fd(n % 10, fd, total);
		}
		else
		{
			total++;
			c = n + '0';
			write(fd, &c, 1);
		}
	}
	return total;
}
