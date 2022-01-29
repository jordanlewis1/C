/*
    This program contains a few compile-time syntax errors and some run-time
    errors -- a seg fault and a couple logic bugs.  Find and correct all the
    errors.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printSum();
    return 0;
}

void printSum() {
    char line[10];
    char *buf = NULL;
    int n;
    printf("Enter a number:\n");
    fgets(line, 10, stdin);
    if (line != NULL) 
        strtok(line, "\n");
    n = atoi(line);
    sprintf(buf, "The sum from 1 to %d is %d.", n, sumToN(n));
    printf("%s\n", buf);
}

int sumToN(int num) {
    int i;
    int sum = 0;
    for (i = 1; i < num; i++)
        sum = i;
    return sum;
}
