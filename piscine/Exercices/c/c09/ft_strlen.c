#include <unistd.h>

int ft_strlen(char *str)
{
	if (!str)
		return (0);
	return (ft_strlen(++str) + 1);
}

int ft_strcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (0);
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (ft_strcmp(++s1, ++s2));
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	if (!*s1 && !*s2)
		return (0);
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (ft_strncmp(++s1, ++s2, n - 1));
}

char *ft_strcpy(char *dest, char *src)
{
	if (!*src)
	{
		*dest = '\0';
		return (dest);
	}
	*dest = *src;
	return (ft_strcpy(++dest, ++src));
}

int occ_z(char *str)
{
	int cout = 0;
	while (*str)
	{
		if (*str == 'z')
			cout++;
		str++;
	}
	return cout;
}

void ft_putnbr(int n)
{
	long n1;

	n1 = n;

	if (n < 0)
	{
		write(1, "-", 1);
		n1 = -n1;
	}
	if (n1 > 9)
	{
		ft_putnbr(n1 / 10);
	}
	n1 = n1 % 10;
	n1 = n1 + '0';
	write(1, &n1, 1);
}

int main ()
{
	int n = 0;
	while (n < 101)
	{
		if (!(n % 5) && !(n % 3))
			write(1, "fizzbuzz\n", 9);
		else if (!(n % 3))
			write(1, "fizz\n", 5);
		else if (!(n % 5)) 
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(n);
			write (1, "\n", 1);
		}
		n++;
	}
}

