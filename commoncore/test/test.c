#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 256

char *readNextLine(int fd) {
    static char buffer[MAX_LINE_LENGTH];
    int bytesRead;
    int position = 0;

    while (1) {
        char currentChar;
        bytesRead = read(fd, &currentChar, 1);

        if (bytesRead == -1) {
            perror("Error reading file");
            return NULL;
        }

        if (bytesRead == 0 || currentChar == '\n') {
            if (position == 0 && bytesRead == 0) {
                return NULL;
            }
            buffer[position++] = '\0';
            return buffer;
        }

        buffer[position++] = currentChar;

        if (position >= MAX_LINE_LENGTH - 1) {
            buffer[position] = '\0';
            return buffer;
        }
    }
}

int main() {
    const char *filePath = "/home/goncalo1021pt/42/commoncore/get_next_line/get_next_line.c";

    int fileFd = open(filePath, O_RDONLY);
    if (fileFd == -1) {
        perror("Unable to open file");
        return 1;
    }

    char *line;
    while ((line = readNextLine(fileFd)) != NULL) {
        printf("Read line: %s\n", line);
    }

    close(fileFd);

    return 0;
}


