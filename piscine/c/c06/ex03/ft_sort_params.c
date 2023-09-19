/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:02:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/11 12:35:48 by gfontao-         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	ctd;

	ctd = 0;
	while (s1[ctd] == s2[ctd] && (s1[ctd] != '\0' && s2[ctd] != '\0'))
	{
		ctd++;
	}
	return (s1[ctd] - s2[ctd]);
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

int	main(int argc, char **argv)
{
	char	*temp;
	int		ctd;
	int		ctd1;

	ctd = 1;
	ctd1 = 2;
	while (ctd < argc)
	{
		while (ctd1 < argc)
		{
			if (ft_strcmp(argv[ctd], argv[ctd1]) > 0)
			{
				temp = argv[ctd];
				argv[ctd] = argv[ctd1];
				argv[ctd1] = temp;
			}
			ctd1++;
		}
		write(1, argv[ctd], ft_strlen(argv[ctd]));
		write(1, "\n", 1);
		ctd++;
		ctd1 = ctd + 1;
	}
	return (0);
}
