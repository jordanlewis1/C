#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    int pipefd[2], rc;
    
    

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    rc = fork();
    if (rc == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (rc == 0) {    /* Child reads from pipe */
        close(pipefd[1]);   
               /* Close unused write end */
        char buf;

        while (read(pipefd[0], &buf, 1) > 0){
            write(STDOUT_FILENO, &buf, 1);
}
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
        
        close(pipefd[0]);
        int i = open(argv[1], O_RDONLY);
        
        while (read(i, &buf, 1) > 0) {
            write(pipefd[1], &buf, 1);
        }
        close(pipefd[1]);
        fsync(i);
        close(i);
        exit (EXIT_SUCCESS);
 

    }
    rc = fork();
    if (rc == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(rc == 0){
    close(pipefd[1]);
    char buf;
    int i = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR) ;
    while (read(pipefd[0], &buf, 1) > 0) {
           write(i, &buf, 1);
    }
    
    close(pipefd[0]);
    fsync(i);
    close(i);
    exit (EXIT_SUCCESS);
    
    }
    
    close(pipefd[0]);
    close(pipefd[1]);
    
    wait(NULL);
    wait(NULL);

}
