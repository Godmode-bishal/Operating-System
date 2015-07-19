//Process creation using fork()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc,char *argv)
{
    if(argc!=3)
    {
	printf("\nNot enough arguments\n");
        exit(-1);
    }
    pid_t pid;
    int x=5,return_val;
    pid=fork();
    if(pid<0)
    {
        printf("\nProcess creation unsuccessful\n");
        exit(-1);
    }
    else if(pid==0)
    {
	printf("\nChild starts\n");
	return_val=execl(argv[1],argv[2],NULL);
	if(return_val<0)
	{
		printf("\nException has occured\n");
		exit(-1);
	}        
    }
    else
    {
        wait();
	printf("\nChild terminated\n");
    }
return 0;
}   
        
