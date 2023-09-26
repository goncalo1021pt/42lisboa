#include <unistd.h>
#include <fcntl.h>

int	ft_readfile (char *filename)
{
	int		fd;
	int		br;
	char 	buffer[100];

	fd = open(filename, O_RDONLY);
	if(fd < 0)
		return (fd);
	while ((br = read(fd, buffer, 100)) > 0)
		write(1, buffer, br);
	close(fd);
	return (0);
}
