#include <unistd.h>
//#include <stdio.h>

	int	ft_strlen(char *str)
	{
		int	ctd;

		ctd = 0;
		while (str[ctd] != '\0')
			ctd++;
		return ctd;
	}

/*int main(){
	int n;

	n = ft_strlen("teste");
	printf("%d", n);
}*/