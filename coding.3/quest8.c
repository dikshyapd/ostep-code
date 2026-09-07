#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fds[2];
    pipe(fds);

    int rc1 = fork();
    if (rc1 == 0) {
        close(fds[0]);
        write(fds[1],"childone\n",9);
        close(fds[1]);
        exit(0);
    }
    int rc2 = fork();
    if (rc2 == 0) {
        close(fds[1]); 
        char buf[100];
        int n = read(fds[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
        exit(0);
    }

    close(fds[0]);
    close(fds[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*********************************************
   Your name: Dia Paudel

   Question 8: The pipe allows the children to communicate with each
   other. On one end of the pipe is the read and the other has the
   write. In this case, child B read the message that child A wrote,
   and it passed through the pipe rather than a variable or a file, and
   all done through the kernel. Closing unused ends meant that each
   process only holds the end it actually uses, which keeps the pipe's
   communication clean and predictable instead of leaving both ends
   open and confusing which process is meant to do which job.
*********************************************/