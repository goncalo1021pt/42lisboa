/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:16:23 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/05 11:32:31 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_char_is_alpha(char str)
{
	if (!((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')))
	{
		return (0);
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	char	*original;

	original = str;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Z'))
		{
			*str = *str + 32;
		}
		str++;
	}
	return (original);
}

int	ft_is_charnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		ctd;
	char	*inicial;

	inicial = str;
	ctd = 0;
	ft_strlowcase(str);
	while (str[ctd] != '\0')
	{
		if (ctd == 0 && ((str[ctd] >= 'a' && str[ctd] <= 'z')))
		{
			str[ctd] -= 32;
		}
		else if (str[ctd] >= 'a' && str[ctd] <= 'z')
		{
			if (ft_is_charnum(str[ctd - 1]))
			{
				str[ctd] -= 32;
			}
		}
		ctd++;
	}
	return (inicial);
}

/*int	main(void)
{
	char c[1000] = "salu9t,   coM+meNt t__u vas ?";
	char *result;

	result = ft_strcapitalize(c);
	printf("%s", result);
	return (0);
}*/