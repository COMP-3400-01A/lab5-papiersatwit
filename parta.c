#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Declare the buffer to use. Do NOT change!
    enum { BUFSIZE = 8 };
    char buffer[BUFSIZE];
    // TODO: Complete and document

    int upper = 0, lower = 0, number = 0, space = 0, other = 0;

    if (argc != 2) {
        printf("USAGE: %s FILE\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFSIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            unsigned char c = buffer[i];

            if (isupper(c))
                upper++;
            else if (islower(c))
                lower++;
            else if (isdigit(c))
                number++;
            else if (isspace(c))
                space++;
            else
                other++;
        }
    }

    close(fd);

    printf("Upper,%d\n", upper);
    printf("Lower,%d\n", lower);
    printf("Number,%d\n", number);
    printf("Space,%d\n", space);
    printf("Others,%d\n", other);
}
