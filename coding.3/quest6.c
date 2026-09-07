#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc1 = fork();
    if (rc1 == 0) {
        printf("child 1 (pid:%d)\n", (int) getpid());
        exit(0);
    }

    int rc2 = fork();
    if (rc2 == 0) {
        printf("child 2 (pid:%d)\n", (int) getpid());
        exit(0);
    }

    int wp = waitpid(rc2, NULL, 0);
    printf("waitpid() returned %d, and rc2 was %d\n", wp, rc2);

    return 0;
}
/*********************************************
   Your name: Dia Paudel

   Question 6: The waitpid() function would be useful when the parent
   has multiple children, and specifically wants the order of output to
   be a certain order of execution. The wait() function only allows the
   parent to wait for whichever child happens to finish first, with no
   way to choose which one. But if there are more, then the waitpid()
   allows for the parent to wait for one specific child to finish then
   proceed. Without this, multiple children would make it difficult to
   have predictable results.
*********************************************/