#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}

/*********************************************
   Your name: Dia Paudel

   output: hello
   goodbye
   
   Question 3: Yes, it does reliably print first to an extent. We set a
   short timer for the parent using sleep() so it waits a bit while the
   child prints. Although this is reliable, we cannot be certain it will
   work 100% of the time because, in rare instances, if there are
   resource issues or something similar, there's a chance the parent
   could still print first. But this is a quick wait that will highly
   likely work.
*********************************************/
