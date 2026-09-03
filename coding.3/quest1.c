#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
int x= 100;
printf("before fork: x = %d\n",x);
//excuted sucessfully
int rc = fork();
if (rc < 0){
fprintf(stderr,"fork failed\n");
exit(1);
} else if (rc==0){
}else {
}
return 0;
}
