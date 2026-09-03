
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
exit(1); } else if (rc==0){
 // child process
        printf("child sees: x = %d (pid:%d)\n", x, (int) getpid());
        x = 200;
        printf("child changed: x = %d (pid:%d)\n", x, (int) getpid());
int rc_wait_child = wait(NULL);
printf("child: wait() returned %d (pid:%d)\n", rc_wait_child, (int) getpid());
}else {
 // parent process
        int rc_wait = wait(NULL);
        printf("parent: child %d finished, wait() returned %d (pid:%d)\n",
               rc, rc_wait, (int) getpid());
    }
return 0;}
/*********************************************
Your name:   Dia Paudel

before fork: x = 100
child sees: x = 100 (pid:58846)
child changed: x = 200 (pid:58846)
child: wait() returned -1 (pid:58846)
parent: child 58846 finished, wait() returned 58846 (pid:58845)

   Question 5: The wait() system call  causes the parent to block/come to a pause  until a child process
   finishes, and it returns the PID of the child that exited. When I  placed the wait() call for the child, the 
returned PID value was the same as the child's own PID.
   When wait() is called inside the child process instead, it returns -1,
   because that child has no children of its own to wait for.
*********************************************/
