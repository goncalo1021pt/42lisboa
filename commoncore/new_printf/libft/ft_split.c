/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:16:31 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/02 23:14:14 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Recives a string splits it into words based non the char c
//Returns a array of strings with those words

static int	count_word(char *str, char c)
{
	int	ctd;
	int	total;

	ctd = 0;
	total = 0;
	while (str[ctd] != '\0')
	{
		while (str[ctd] && str[ctd] == c)
			ctd++;
		if (str[ctd])
			total++;
		while (str[ctd] && str[ctd] != c)
			ctd++;
	}
	return (total);
}

static char	*word_aloc(char *str, char c)
{
	char	*word;
	int		word_len;
	int		ctd;

	ctd = 0;
	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	word = (char *)malloc(word_len + 1);
	if (!word)
		return (NULL);
	while (ctd < word_len)
	{
		word[ctd] = str[ctd];
		ctd++;
	}
	word[ctd] = '\0';
	return (word);
}

void	*free_str(char **out, int ctd)
{
	while (ctd-- >= 0)
		free(out[ctd]);
	free(out);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		ctd;
	char	*str;

	str = (char *)s;
	ctd = 0;
	out = (char **)malloc((count_word(str, c) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			out[ctd] = word_aloc(str, c);
			if (!out[ctd])
				return (free_str(out, ctd - 1));
			ctd++;
		}
		while (*str && *str != c)
			str++;
	}
	out[ctd] = 0;
	return (out);
}

/* int	main(void)
{
	int		index;
	char	**split;
	split = ft_split("teste de string 4     ", ' ');
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
	free(split);
} */ 