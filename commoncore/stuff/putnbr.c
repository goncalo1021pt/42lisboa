#include <unistd.h>
#include <limits.h>
void ft_putnbr(int n)
{
	if (n < -9 || n > 9)
		ft_putnbr(n / 10);
	else if (n < 0)
		write(1, "-", 1);
	write(1, &"0123456789"[(n % 10) * ((n > 0) - (n < 0))], 1);
}

int main()
{
	ft_putnbr(-2147483647);
}