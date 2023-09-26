/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:41:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/20 09:04:04 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	ctd;
	int	signal;
	int	num;

	num = 0;
	signal = 0;
	ctd = 0;
	while ((str[ctd] == ' ') || (str[ctd] > 8 && str[ctd] < 14))
		ctd++;
	while (str[ctd] == '+' || str[ctd] == '-')
	{
		if (str[ctd] == '-')
			signal++;
		ctd++;
	}
	while (str[ctd] >= '0' && str[ctd] <= '9')
	{
		num *= 10;
		num = num + (str[ctd] - '0');
		ctd++;
	}
	if (signal % 2 == 1)
		num *= -1;
	return (num);
}

/*int main()
{
	printf("testing atoi: %d\n", ft_atoi("   \t\n\r\v\f-+-++-452453aaaA"));
}*/
