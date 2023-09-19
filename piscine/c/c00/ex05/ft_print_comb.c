/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:04:59 by gfontao-          #+#    #+#             */
/*   Updated: 2023/08/31 16:33:01 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, char d, char u)
{
	if (u > d && d > c)
	{
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, &u, 1); 
		if (!(c == '7' && d == '8' && u == '9'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	c;
	char	d;
	char	u;

	c = '0';
	d = '0';
	u = '0';
	while (c <= '9')
	{
		while (d <= '9')
		{
			while (u <= '9')
			{
				ft_putchar(c, d, u);
				u++;
			}
			d++;
			u = '0';
		}
		c++;
		d = '0';
		u = '0';
	}
}
