#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    int fd = open("quest2.output", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        fprintf(stderr, "open failed\n");
        exit(1);
    }

    int rc = fork();
if(rc < 0){
    fprintf(stderr,"child failed\n");
    exit(1);
} else if (rc == 0) {
    // child process
    write(fd,"child\n",6);
} else {
    // parent process
    write(fd,"parent\n",7);
    wait(NULL);
}
close(fd);
return 0;
}

/*********************************************
   Your name: Dia Paudel

   output:
   "parent
   child"

Yes, both the child and the parent can access the same file (fd) 
because, with this program, we saw that they both wrote on the 
same file. The open() was before the fork() happened, so they both
write on the same place, just different positions on the file.
With concurrency, there is unpredictability; we cannot 
be sure if the parent or the child will print first. With this 
program, sometimes the parent can print first or the child can.
   *********************************************/
