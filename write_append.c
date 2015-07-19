//To append content to an existing file.
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char * argv[])
{
    int fd,n,len;
    char buf[100];
    if(argc!=2)
    {
         printf("\nNot enough arguments");
         exit(-1);
    }
    fd=open(argv[1],O_APPEND|O_WRONLY|O_CREAT,0644);
    if(fd<0)
    {
        printf("\nCouldn't open file");
        exit(-1);
    }
    printf("\nEnter ctrl+D to end input\n");
    while((n=read(0,buf,sizeof(buf)))>0)
    {
        len=strlen(buf);
        write(fd,buf,len);
    }
    close(fd);
    return 0;
}
