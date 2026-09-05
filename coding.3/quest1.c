#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
int main(int argc, char *argv[]){
int x= 100;
printf("before fork: x = %d\n",x);
//excuted sucessfully
int rc = fork();
if (rc < 0){
fprintf(stderr,"fork failed\n");
exit(1);
} else if (rc==0){
 // child process
        printf("child sees: x = %d (pid:%d)\n", x, (int) getpid());
        x = 200;
        printf("child changed: x = %d (pid:%d)\n", x, (int) getpid());
int rc_wait_child = wait(NULL);
printf("child: wait() returned %d (pid:%d)\n", rc_wait_child, (int) getpid());
}else {
    // parent process
    printf("parent sees: x = %d (pid:%d)\n", x, (int) getpid());
    x = 300;
    printf("parent changed: x = %d (pid:%d)\n", x, (int) getpid());

    int rc_wait = wait(NULL);
    printf("parent: child %d finished, wait() returned %d (pid:%d)\n",
           rc, rc_wait, (int) getpid());
}
return 0;}

/*********************************************
   Your name: Dia Paudel

   Question 1: Before fork(), x = 100. After fork(), both the parent and
   child have their own copy of the x value, both still equal to 100 at
   the moment of the fork. 
   
   When the child changes x to 200, this only applied to the child;
   the parent's x is still the same. 
   When the parent changes x to 300, the child's copy is unaffected.
   This is because fork() gives the child its own indivisual copy of the
   entire address space meaning they are not sharing memory, 
   so changes made
   by one process are not applied to the other.
*********************************************/