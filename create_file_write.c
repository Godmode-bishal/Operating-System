//Create a file and write contents
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int f,n,len;
    char buf[100];
    if(argc!=2)
    {
        printf("\nNot enough arguments");
        exit(-1);
    }
    f=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(f<0)
    {
        printf("\nProblem creating file");
        exit(-1);
    }
    printf("\nEnter ctrl+D to end input\n");
    while((n=read(0,buf,sizeof(buf)))>0)
    {
        len=strlen(buf);
        write(f,buf,len);
    }
    close(f);
    return 0;
}