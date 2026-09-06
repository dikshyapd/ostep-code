#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *args[] = {"ls", NULL};
        execv("/bin/ls", args);
    } else {
        wait(NULL);
        printf("child (running /bin/ls) is done\n");
    }
    return 0;
}

/*********************************************
   Your name: Dia Paudel

   Question 4: I tested the variants execl() and execv(), which have the
   same results. I realized they were just different ways to access the
   same thing, and depending on what you had, you could use whichever
   one and get to the same place. execl() takes a path and lists the
   arguments individually, while execv() takes a path but uses a vector
   to pass the arguments. There's different variants because it allows
   for more ways to get the same results depending on preference and
   resources.
*********************************************/
