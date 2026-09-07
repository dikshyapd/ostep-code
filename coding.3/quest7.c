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
        close(STDOUT_FILENO);
        printf("child print\n");
    } else {
        wait(NULL);
        printf("parent finished\n");
    }
    return 0;
}

/*********************************************
   Your name: Dia Paudel

   Question 7: When the child tried to printf() after closing stdout,
   there's an internal failure with write() that returns -1, meaning
   there's an error because the destination disappeared. The printf()
   doesn't do anything about it in the display, no crash messages, but
   it just doesn't give an output. So the error is there, it's just not
   showing. In this case, when the child tried to print and the channel
   was closed, it just didn't display the error even though there was
   no destination.
*********************************************/