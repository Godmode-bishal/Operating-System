/* No. of users logged -  cmdpipe.c */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int pfds[2];
    pipe(pfds);
    if(!fork())
    {
        close(1);
        dup(pfds[1]);
        close(pfds[0]);
        execlp("who","who",NULL);
    }
    else
    {
        close(0);
        dup(pdfs[0]);
        close(pdfs[1]);
        execlp("wc","wc",-1,NULL);
    }
}
        
        