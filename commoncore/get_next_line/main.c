#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main() {
	const char *filePath = "/nfs/homes/gfontao-/Documents/42/commoncore/get_next_line/main.c";
	int fileFd = open(filePath, O_RDONLY);
	char *line;

	if (fileFd == -1) {
		perror("Unable to open file");
		return 1;
	}
	if ((line = get_next_line(fileFd)) != NULL) {
		printf("Read line: %s\n", line);
		free(line); 
	}

	close(fileFd);

return 0;
}