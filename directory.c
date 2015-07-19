#include<stdio.h>
#include<stdlib.h>
//#include<sys/types.h>
#include <dirent.h>
int main(int argc, char * argv[])
{
    DIR *dir;
    struct dirent *d;
    if(argc!=2)
    {
	printf("\nFilename not given\n");
	exit(-1);
    }
    if((dir=opendir(argv[1]))==NULL)
    {
	printf("\nCould not open directory\n");
	exit(-1);
    }	
    while(d=readdir(dir))
    {
	printf("%s\n",d->d_name);
    }
    closedir(dir);
}        
