/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:02:09 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/11 12:14:02 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

int	main(int argc, char *argv[])
{
	int	ctd;

	ctd = argc - 1;
	while (ctd > 0)
	{
		write(1, argv[ctd], ft_strlen(argv[ctd]));
		write(1, "\n", 1);
		ctd--;
	}
	return (0);
}
