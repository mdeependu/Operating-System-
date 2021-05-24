#include<stdio.h>
int main()
{
    int pid[10];
    int at[10];
    int et[10];
    int ct[10];
    int wt[10];
    int tat[10];
    int i,j,k,n,x,t1,t2,t3;
    int total_wt = 0;
    int total_tat = 0;
    printf("No. of Processes :\n");
    scanf("%d",&n);
    printf("\nProcess Id:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pid[i]);
    printf("\nArrival time :\n");
    for(i=0;i<n;i++)
		scanf("%d",&at[i]);
    printf("\nExecution time :\n");
    for(i=0;i<n;i++)
		scanf("%d",&et[i]);

        for(i=0;i<n;i++)
        {
            for (j=0; j<n; j++)
            {
                if (et[j] > et[j+1])
                {
                 t1=at[j];
                 at[j]=at[j+1];
                at[j+1]=t1;

                t2=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=t2;

                t3=et[j];
                et[j]=et[j+1];
                et[j+1]=t3;
                }
           }


        }
    for(int k=0;k<n;k++)
 {
        if (k==0)
        {
            ct[0]=et[0];
            tat[0]=ct[0];
            wt[0]=tat[0]-et[0];

        }
        else{
            ct[k]=ct[k-1]+et[k];
            tat[k]=ct[k]-at[k];
            wt[k]=tat[k]-et[k];
        }
 }

    printf("\nProcess Id:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",pid[j]);
        }

    printf("\n\nArrival Time:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",at[j]);
        }

    printf("\n\nBurst Time:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",et[j]);
        }

    printf("\n\nCompletion Time:");
    for(k=0;k<n;k++)
        {
            printf("%d ",ct[k]);
        }

    printf("\n\nTurn Around Time:");
    for(k=0;k<n;k++)
        {
            printf("%d ",tat[k]);
        }

    printf("\n\nWaiting Time:");
    for(k=0;k<n;k++)
        {
            printf("%d ",wt[k]);
            total_wt += wt[k];
        }

    printf("\n\nAverage Waiting Time: ");
    printf("\n%d",total_wt/n);
    printf("\n");
    return 0;
}
