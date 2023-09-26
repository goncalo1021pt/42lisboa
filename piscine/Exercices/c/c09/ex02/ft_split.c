/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:16:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/17 16:19:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_separator(char c, char *charset)
{
	int	ctd;

	ctd = 0;
	while (charset[ctd] != '\0')
	{
		if (c == charset[ctd])
			return (1);
		ctd++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	ctd;
	int	total;

	ctd = 0;
	total = 0;
	while (str[ctd] != '\0')
	{
		while (str[ctd] && (check_separator(str[ctd], charset)))
			ctd++;
		if (str[ctd])
			total++;
		while (str[ctd] && !(check_separator(str[ctd], charset)))
			ctd++;
	}
	return (total);
}

int	word_leng(char *str, char *charset)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] && !check_separator(str[ctd], charset))
		ctd++;
	return (ctd);
}

char	*word_aloc(char *str, char *charset)
{
	char	*word;
	int		word_len;
	int		ctd;

	ctd = 0;
	word_len = word_leng(str, charset);
	word = (char *)malloc(word_len + 1);
	while (ctd < word_len)
	{
		word[ctd] = str[ctd];
		ctd++;
	}
	word[ctd] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**out;
	int		ctd;

	ctd = 0;
	out = (char **)malloc((count_word(str, charset) + 1) * sizeof(char *));
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset))
			str++;
		if (*str != '\0')
		{
			out[ctd] = word_aloc(str, charset);
			ctd++;
		}
		while (*str && !check_separator(*str, charset))
			str++;
	}
	out[ctd] = 0;
	return (out);
}

/* int	main()
{
	int		index;
	char	**split;
	split = ft_split("teste de string 4     ", " ");
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
	free(split);
} */