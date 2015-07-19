//Process creation using fork()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    int x=5;
    pid=fork();
    if(pid<0)
    {
        printf("\nProcess creation unsuccessful\n");
        exit(-1);
    }
    else if(pid==0)
    {
        printf("\nChild process. Process ID is %d, value of x is %d, process id of the parent is %d\n",getpid(),x,getppid());
    }
    else
    {
        printf("\nParent process. Process ID is %d, value of x is %d, process id of the shell is %d\n",getpid(),x,getppid());
    }
return 0;
}   
        
