/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:01:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/19 18:01:54 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

void	concatonator(char **dest, char *str, char *sep)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (ctd < ft_strlen(str))
	{
		**dest = str[ctd];
		(*dest)++;
		ctd++;
	}
	ctd2 = 0;
	while (ctd2 < ft_strlen(sep))
	{
		**dest = sep[ctd2];
		(*dest)++;
		ctd2++;
	}
}

int	size_string(int size, char **strs, char *sep)
{
	int	ctd;
	int	szstr;

	ctd = 0;
	szstr = 0; 
	while (ctd < size)
	{
		szstr += ft_strlen(strs[ctd]);
		if (ctd < size -1)
			szstr += ft_strlen(sep);
		ctd++;
	}
	return (szstr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstr;
	char	*original;
	int		szstr;
	int		ctd;

	ctd = 0;
	szstr = size_string(size, strs, sep);
	newstr = (char *)malloc(szstr + 1);
	original = newstr;
	if (size == 0)
		return (newstr);
	ctd = 0;
	while (ctd < size)
	{
		if (ctd < size - 1)
			concatonator(&newstr, strs[ctd], sep);
		else
			concatonator(&newstr, strs[ctd], "");
		ctd++;
	}
	*newstr = '\0';
	return (original);
}

/*int main(int argc, char *argv[])
{
	char *str = ft_strjoin(argc,argv,"+");
	printf("%s", str);
	free(str);
	return (0);
}*/