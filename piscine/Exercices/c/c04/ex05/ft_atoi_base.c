/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:28:22 by gfontao-          #+#    #+#             */
/*   Updated: 2024/09/12 02:36:27 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct limit
{
	int	i;
	int	signal;
	int	num;
	int	bl;
}		t_limit;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_not_valid(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) < 2)
		return (0);
	if (s[i] == '+' || s[i] == '-' || s[i] <= ' ')
		return (1);
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j] || s[j] == '+' || s[j] == '-' || s[j] <= ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	t_limit	v;

	if (base_not_valid(base))
		return (0);
	v.num = 0;
	v.signal = 1;
	v.i = 0;
	v.bl = ft_strlen(base);
	while ((str[v.i] == ' ') || (str[v.i] > 8 && str[v.i] < 14))
		v.i++;
	while (str[v.i] == '+' || str[v.i] == '-')
	{
		if (str[v.i] == '-')
			v.signal *= -1;
		v.i++;
	}
	while (is_base(str[v.i], base) != -1)
	{
		v.num *= v.bl;
		v.num = v.num + is_base(str[v.i], base);
		v.i++;
	}
	return (v.num * v.signal);
}

/*int main()
{
	printf("testing atoi: %d\n", ft_atoi_base(" --FF","0123456789ABCDEF"));
}*/
