#include "functions.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		ft_readfile(argv[1]);
		if (ft_readfile(argv[1]) == -1)
			ft_puterr("Cannot read file.\n");		
	}
	return (0);
}