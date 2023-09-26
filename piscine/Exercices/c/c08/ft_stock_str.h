#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
void	ft_show_tab(struct s_stock_str *par);

#endif