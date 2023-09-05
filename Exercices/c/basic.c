#include <unistd.h>


int main(void){

    


    return 0;
}


char c;
write(1, &c, 1);



#include <unistd.h>

void	ft_putchar(char*c)
{
	if (c[2] > c[1] && c[1] > c[0])
	{
		write(1, &c[0], 1);
		write(1, &c[1], 1);
		write(1, &c[2], 1); 
		if (!(c[0] == '7' && c[1] == '8' && c[2] == '9'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	a[3];
	char	c;
	char	d;
	char	u;

	c = '0';
	d = '0';
	u = '0';
	while (c <= '9')
	{
		while (d <= '9')
		{
			while (u <= '9')
			{
				a[0] = c;
				a[1] = d;
				a[2] = u;
				ft_putchar(a);
				u++;
			}
			d++;
			u = '0';
		}
		c++;
		d = '0';
		u = '0';
	}
}

int main(){   
    ft_print_comb();
    return 0;
}