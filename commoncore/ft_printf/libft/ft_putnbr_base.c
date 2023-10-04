/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:56:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/04 18:25:38 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_not_valid(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '+' || s[i] == '-' || s[i] < ' ')
		return (1);
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j] || s[j] == '+' || s[j] == '-' || s[i] < ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int			bl;
	char		c;
	static int	total;

	bl = ft_strlen(base);
	if (bl < 2 || base_not_valid(base))
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		total++;
		write(1, "-", 1);
	}
	if ((nbr / bl) > 0)
	{
		ft_putnbr_base(nbr / bl, base);
		ft_putnbr_base(nbr % bl, base);
	}
	else 
	{
		c = base[nbr];
		total++;
		write(1, &c, 1);
	}
	return (total);
}
