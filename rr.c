/*Round robin  scheduling - rr.c  */
#include <stdio.h>
#include<stdlib.h>
static int *ar;
int main()
{
    int i,t,b[5],w[5],tur[5],j,k=0,l;
    ar=(int*)calloc(20,sizeof(int));
    printf("Enter time quanta\n");
    scanf(" %d",&t);
    printf("Enter burst time for all 5 processes\n");
    for(i=0;i<5;i++)
        scanf(" %d",&b[i]);
    i=0;
    for(j=0;j<71;j++)
        printf("-");
    printf("\n|");
    ar[k]=0;
    k++;
    while(b[i]!=0)
    {
        if(b[i]<t)
        {
            printf(" P%d |",i+1);
            ar[k]=ar[k-1]+b[i];
            b[i]=0;
            i++;
            k++;
        }
        else
        {
            printf(" P%d |",i+1);
            ar[k]=ar[k-1]+t;
            b[i]-=t;
            i++;
            k++;
        }
        if(i==5)
            i=0;
        if(b[i]==0)
        {
            for(l=0;l<5 && b[i]==0;l++)
            {
                i++;
                if(i==5)
                    i=0;
            }
        }
    }
    printf("\n");
    for(j=0;j<71;j++)
        printf("-");
    printf("\n");
    printf("%d    ",ar[0]);
    for(j=1;j<20;j++)
    {
        if(ar[j])
            {
                if(ar[j+1]>9)
                    printf("%d   ",ar[j]);
                else
                    printf("%d    ",ar[j]);
            }
        
    }
    return 0;
}