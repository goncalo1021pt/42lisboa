/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:32:15 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/13 12:35:28 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	ctd;

	ctd = 0;
	while (src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	dest[ctd] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(ft_strlen(src) + 1);
	ft_strcpy(str, src);
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*out;
	int			ctd;

	out = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!out)
		return (0);
	ctd = 0;
	while (ctd < ac)
	{
		out[ctd].size = ft_strlen(av[ctd]);
		out[ctd].str = av[ctd];
		out[ctd].copy = ft_strdup(out[ctd].str);
		ctd++;
	}
	out[ctd].size = 0;
	out[ctd].str = 0;
	out[ctd].copy = 0;
	return (out);
}

/*int main(int argc, char *argv[])
{
	t_stock_str *test;

	test = ft_strs_to_tab(argc, argv);
	ft_show_tab(test);
}*/