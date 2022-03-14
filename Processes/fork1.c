#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    //char path[50];
	//getcwd(path, 80-6);
	//strcat(path, "/file");
    int f = open("file",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  S_IRUSR | S_IWUSR);
    
    assert(f >= 0);
    
    int rc = fork();
    //fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
    char *buffer;
        buffer = "hello, I am child\n";
        write(f, buffer, strlen(buffer));
    } else {
    char *buffer;

	       buffer = "hello, I am parent\n";
	       write(f, buffer, strlen(buffer));
    }
    
    close(f);
    return 0;
}
