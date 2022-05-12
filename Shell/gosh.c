#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    char *line;
    size_t n;
    char *token;
    char *tokens[200];
    int len;
    char *nxt;
    int numOfTokens;
    int i;
    int x;
    int flag;
    char *tokens2[200];
    int newst;
    //fork
    int rc;
    rc = 0;
    
    if (argc == 2)
    {
        //printf("Batch mode \n");
        //code snippets
        int fd = open(argv[1], O_RDONLY);
        dup2(fd, STDIN_FILENO);
        close(fd);
        // fprintf(fd, "Hello World");
        // if (fd == -1){
        // printf("Error: no such file \n");
        // }
        //close(fd);
    }
    
    if (argc == 1){
        //Jordan mode
        printf("Jordan mode \n");
        printf("Type *Tom* to play mini game.\n");
        //printf("gosh> ");
    }
    while (1) {
         line = NULL;
         n = 0;
         flag = 0;
         
        if (argc == 1){
            //printf("Jordan mode \n");
            printf("gosh> ");
        }
        len = getline(&line, &n, stdin);
        nxt = line;
         //printf("gosh> ");

        //control d exit
         if (len == -1 && (errno == 0||9)){
                //free(line);
                printf("Goodbye Tom\n");
                exit(0);
         }
            
         numOfTokens = 0;
            // token = strsep(&nxt, " \t\n");
         i = 0;
         //separate 

            //char *dup = strdup(nxt);
         token = strsep(&nxt, " \t\n");
         while (token != NULL){
            
            if(strlen(token) > 0){
                //execvp(tokens[i], tokens);
                //printf("tokens[%s] = %s", i, tokens[i]);
                //token = strsep(&nxt, " \t\n");
                //printf("%sThe token was added to the list.\n", token);
                tokens[i] = strdup(token);
                i++;
                numOfTokens++;
                //tokens[i];
                // get next token
            }
            token = strsep(&nxt, " \t\n");
                //tokens[i] = NULL;
                //tokens[i + 1] = NULL;
         }
         tokens[i] = NULL;
         tokens[i+1] = NULL;
         free(line);

         if (tokens[0] == NULL && numOfTokens == 0) {
                continue;
            }
            // compare strings
            //if (strcmp(tokens[0], ("^[[A") == 0){
                
            //}
            if (strcmp(tokens[0], ("cd")) == 0){
                if (numOfTokens > 2){
                    printf("Invalid Input, You need 42 less arguments.\nYou Lose!!!\n");
                    exit(1);
                }
                else if (numOfTokens == 2){
                //check to make sure it is an actual directory
                    if (chdir(tokens[1]) == 0) {              
                        printf("Changing directory to %s\n", tokens[1]);
                        chdir(tokens[1]);
                        flag = 1;
                     }
                    //if (strcmp(tokens[1], ("Tom")) == 0){
                        //printf("The Easter Egg is not here. Lets look somewhere else. \nHint: Maybe it's hidden is his directory.\n");
                    //}
                    //Easter Egg
                    if(strcmp(tokens[1], ("Tom"))== 0){
                        printf("\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡼⠃⢀⣀⣀⣀⣀⣀⣀⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣴⠟⠁⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠄⠙⠷⣄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⡾⠁⢠⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⢀⡴⠋⠄⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠈⠳⣦⡀⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠟⠄⣰⣿⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡏⠄⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠈⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣰⠏⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣼⠋⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⠉⠉⠉⠉⠉⠉⢹⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡾⠁⢠⣾⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸⡟⠛⣿⠄⢸⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⣠⡟⠄⣠⣿⣿⣿⣿⡟⠁⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣡⠞⠁⣠⣾⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⣰⠏⠄⣴⣿⣿⣿⣿⡟⠄⠄⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣰⠟⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⠟⠁⣠⡿⠄⠄\n⠄⠄⠄⠄⠄⠄⣼⠋⢀⣼⣿⣿⣿⣿⠏⢀⡆⠄⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣴⠟⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⠟⠁⣠⠞⠋⠄⠄⠄\n⠄⠄⠄⠄⢀⡾⠃⢀⣾⣿⣿⣿⣿⠏⢠⡞⡇⠄⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡴⠋⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⠟⠁⣠⠞⠁⠄⠄⠄⠄⠄\n⠄⠄⠄⣠⡞⠁⣠⣿⣿⣿⣿⣿⠃⠄⠛⠒⠃⠄⣿⣿⣿⣿⣿⣿⣿⠄⠘⠛⠛⠛⡇⠄⠄⠄⠄⠄⠄⢀⡴⠋⢀⣴⣿⣿⣿⣿⣿⣿⣿⡿⠋⠄⣠⠞⠁⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⣰⠏⠄⣰⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⠄⠄⡇⠄⠄⠄⠄⢀⡾⠋⢀⣴⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣴⠞⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⣿⠄⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⡇⠄⠄⠄⢸⡏⠄⣴⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣴⠟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⣿⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⡇⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⠋⢀⡴⠋⢰⡶⠶⠶⠶⠶⠶⠶⠶⠶⠶⣶⠄⠄\n⠄⠄⣿⠄⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠄⠄⡇⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⠄⠈⠉⠉⠉⠁⠄⣶⣶⣶⣶⣶⣶⡆⠄⣿⠄⠄\n⠄⠄⣿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⡄⠄⣿⣿⣿⣿⣿⣿⣿⠄⢰⡶⠶⠶⠇⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡇⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⡇⠄⠄⠄⠄⠄⠄⢸⡇⠄⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠄⣿⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠃⠄⠄⠄⠄⠄⠄⠘⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
                        printf("You have found the Easter Egg.\nYou WIN!!!\n");
                        exit(0);
                    }
                }
                else
                {
                    printf("Go Home\n");
                    chdir(getenv("HOME"));
                    flag = 1;
                }
            }
            //mini game
            //if (strcmp(tokens[0], ("^[[A")) == 0){
                            //tokens[i] = t
                        //}
            
            if (strcmp(tokens[0], ("Tom")) == 0){
                printf("Tom is hiding the Easter Egg.  Lets find it!!\nType *hint* for a hint.\n");
            }
            if (strcmp(tokens[0], ("hint")) == 0){
                printf("Hint: Maybe it's hidden is his directory.\n");
                //exit(0);
            }
            if (flag == 1)
            {
                //current working directory.
                char pwd[40];
                printf("Current working directory is %s\n", getcwd(pwd, sizeof(pwd)));
            }

            // free(line);
            if (strcmp(tokens[0], ("exit")) == 0)
            {
                printf("Goodbye Tom\n");
                exit(0);
            }

            //high level
            //how to parse through command line 
            //int  = 0;
            //int counter = 0;
            //while (tokens < CLI length){
            // if (firstdup[w_c] != &){
            //sec_dup[csd = firstdup[w_c]
            //len_secdup++
            //csd++
            //}
            //else{
            //csd = 0;
            //len_sec_dup = 0;
            //}
            //w_c
            //}
            
            //}
            
            
            //built ins
            if (flag == 0)
            {
                i=0;
                while(tokens[i] != NULL){
                x=0;
                while ((tokens[i] != NULL) && (strcmp(tokens[i], "&") != 0))
         
                {   //trial do not use
                    //if (strcmp(tokens[0], ("^[[A")) == 0){
                            //tokens[i] = t
                        //}
                    // string comparison
                    if (strcmp(tokens[i], ">") == 0)
                    {
                        i++;
                        if (strcmp(tokens[i], ">") == 0)
                        {
                            printf("Error 42: You need 42 more arguments\nYou Lose!!!");
                        }
                        
                        //check for null or &
                        if ((tokens[i + 1] == NULL) || (strcmp(tokens[i + 1], "&") == 0))
                        {
                            newst = dup(1);
                            //redir
                            int fd2 = open(tokens[i], O_WRONLY | O_CREAT | O_TRUNC ,
                                                      S_IRUSR | S_IWUSR) ;
                            //writen to stout file
                            assert(fd2 >= 0);
                            dup2(fd2, STDOUT_FILENO);
                            dup2(fd2, STDERR_FILENO);
                            close(fd2);
                            i++;
                            
                        }else {
                        printf("Error 42: You need 42 more arguments\n");
                        exit(1);
                        }
                        
                    }
                    tokens2[x] = tokens[i];
                    i++;
                    x++;
                }
                tokens2[x] = NULL;
                i++;
                //create forks
                rc = fork();
                if (rc < 0){
                printf("Error 4242: You need to run 42 more forks.\n");
                //exit 
                exit(1);
                }
                if (rc == 0){
                
                execvp(tokens2[0], tokens2);
                //error for invalid
                //printf("Error 424242424242: 42 Invalid Inputs.\n");
                exit(1);
            }
            
     
        } 
        dup2(newst, 1);
        close(newst);
    }
    while((flag == 0) && (wait(NULL) != rc));
    /*
    code snippets
    nxt = line;

    token = strsep(&nxt, " \t\n");

    if (strlen(token) > 0)

    //free(line);
    fprintf( stdin, "An error has occured");
    //int fd = open(argv[1], O_RDONLY);
    //dup2(fd, STDIN_FILENO);

    //close(fd);
    */
    //return 0;
}
}
