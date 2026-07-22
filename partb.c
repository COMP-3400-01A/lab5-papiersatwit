#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    // TODO: Complete and document
    if (argc != 3) {
        printf("USAGE: partb FILEIN FILEOUT\n");
        return 1;
    }

    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0770);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);
    close(fd);

    printf("Category,Count\n");
    fflush(stdout);

    char *parta_args[] = {"./parta", argv[1], NULL};

    execv("./parta", parta_args);

    perror("execv");
    return 1;
}
