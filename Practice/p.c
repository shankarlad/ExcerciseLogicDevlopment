#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
int main(){
pid_t pid;
pid = fork();

if(pid==0){
printf("Child process is running... %d \n", getpid());
printf(" having parent... %d \n", getppid());
printf(“Child Exiting\n”);
}
else if (pid > 0){
printf("Parent process is running... %d \n", getpid());
printf(" having parent... %d \n", getppid());
printf(“Parent Exiting\n”);

} 
else{
printf("Error...Something went wrong");
}
}
