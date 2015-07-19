//Process creation using fork()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    int x;
    pid=fork();
    if(pid<0)
    {
        printf("Process creation unsuccessful\n");
        exit(-1);
    }
    else if(pid==0)
    {
        printf("Child starts \n");
 	printf("Odd numbers: ");
        for(x=1;x<=10;x++)
        {
            if(x%2!=0)
                printf("%d ",x);
        }
        printf("\nChild ends\n");
    }
    else
    {
        wait();
        printf("Parent starts \n");
	printf("Even numbers: \n");
        for(x=1;x<=10;x++)
        {
            if(x%2==0)
                printf("%d ",x);
        }
        printf("\nParent ends\n");
    }
return 0;
}   
        
