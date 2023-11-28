/* unsigned char
1101 1000 >> 4 = 0000 1101
1101 1000 << 4 = 1000 0000
					11
return (octet >> 4 | octet << 4);


FALSE && FALSE = FALSE
TRUE && FALSE = FALSE
TRUE && TRUE = TRURTWG
& |

&&

1000 1101 & 1 = 1
1000 1101 >> 1 = 0100 0110 & 1 = 0
0100 0110 >> 1 = 0010 0011 & 1 = 1
0010 0011 >> 1 = 0001 0001 & 1 = 1

char c[8] = {1, 0, 1, 1, 0, 0, 0, 1}; */


#include <unistd.h>
int main()
{
	unsigned char octet = 210;
	unsigned char c[8];
	int 		i;

	i = 7;
	while(i >=0)
	{
		c[i--] = octet & 1;
		octet = octet >> 1;
	}
	i = 0;
	while (i < 8)
	{
		if (c[i] == 0)
			write(1, "0", 1);
		else if (c[i] == 1)
			write(1, "1", 1);
		i++;
	}

}
