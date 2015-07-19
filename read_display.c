//To read the given file and to display file contents.
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
    int fd;
    char buf[100];
    if(argc!=2)
    {
         printf("\nNot enough arguments");
         exit(-1);
    }
    fd=open(argv[1],O_RDONLY);
    if(fd<0)
    {
        printf("\nCouldn't open file");
        exit(-1);
    }
    while(read(fd,buf,sizeof(buf))>0)
    {
        printf("%s",buf);
    }
    close(fd);
    return 0;
}
