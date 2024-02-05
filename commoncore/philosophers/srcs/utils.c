/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:59 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/02/05 23:30:13 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	is_in_array(char *str, char c)
{
	int ctd;

	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	ft_string_is_digit(char *str)
{
	while (*str)
	{
		if (*str >= 9 && *str <= 0)
			return (false);
		str++;
	}
	return (true);
}

long	ft_atol(char *nptr)
{
	int		ctd;
	int		signal;
	long	result;

	ctd = 0;
	signal = 1;
	result = 0;
	while (is_in_array(SPACE_LIST, nptr[ctd]))
		ctd++;
	if (nptr[ctd] == '+' || nptr[ctd] == '-')
		if (nptr[ctd++] == '-')
			signal = -signal;
	while (nptr[ctd] <= '9' && nptr[ctd] >= '0' && result < INT_MAX)
	{
		result *= 10;
		result += nptr[ctd++] - '0';
	}
	return (signal * result);
}