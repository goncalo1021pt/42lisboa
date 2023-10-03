/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:56:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/03 21:06:35 by gfontao-         ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, char *base)
{
	int			bl;
	long int	nb;
	char		c;

	nb = nbr;
	bl = ft_strlen(base);
	if (bl < 2 || base_not_valid(base))
		return ;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if ((nb / bl) > 0)
	{
		ft_putnbr_base(nb / bl, base);
		ft_putnbr_base(nb % bl, base);
	}
	else 
	{
		c = base[nb];
		write(1, &c, 1);
	}
}

/*int		main(void)
{
	ft_putnbr_base(47, "");
	return (0);
}*/
