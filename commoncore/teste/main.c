#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main() {
	const char *filePath = "/home/goncalo1021pt/42/commoncore/teste/main.c";
	int fileFd = open(filePath, O_RDONLY);
	char *line;
	if (fileFd == -1) {
		perror("Unable to open file");
		return 1;
	}
	while ((line = get_next_line(fileFd)) != NULL) {
		printf("%s\n", line);
		free(line); 
	}
	close(fileFd);
return 0;
}