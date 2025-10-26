/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:56:40 by gfontao-          #+#    #+#             */
/*   Updated: 2025/03/19 23:41:47 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define EX_BASE "0123456789ABCDEF"

int	ft_slen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	base_not_valid(char *s)
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
	bl = ft_slen(base);
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
