#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    struct stat sb;

    if (argc == 1) {
        fprintf(stderr, "Usage: ./fs file...\n");
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        if (!stat(argv[i], &sb))
            printf("%s: %ld\n", argv[i], sb.st_size);
        else
            printf("%s: not found\n", argv[i]);
    }

    return 0;
}
