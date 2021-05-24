#include <stdio.h>

int main()
{
    int pid[10];
    int at[10];
    int bt[10];
    int ct[10];
    int tat[10];
    int wt[10];
    int prior[10];
    int total_wt = 0;
    int t1,t2,t3,t4,i,j,n,k;

    printf("No. of Processes : ");
    scanf("%d",&n);

    printf("\nProcess Id :\n");
    for(i=0;i<n;i++)
        {
            scanf("%d",&pid[i]);
        }

    printf("\nArrival time :\n");
    for(i=0;i<n;i++)
        {
            scanf("%d",&at[i]);
        }

    printf("\nExecution time :\n");
    for(i=0;i<n;i++)
        {
            scanf("%d",&bt[i]);
        }

    printf("\nEnter Priority :\n");
    for(i=0;i<n;i++)
        {
            scanf("%d",&prior[i]);
        }

    for(i=0;i<n;i++)
        {
            for (j=0; j<n; j++)
            {
                if (pid[j] > pid[j+1])
                {
                    t1=at[j];
                    at[j]=at[j+1];
                    at[j+1]=t1;

                    t2=pid[j];
                    pid[j]=pid[j+1];
                    pid[j+1]=t2;

                    t3=bt[j];
                    bt[j]=bt[j+1];
                    bt[j+1]=t3;

                    t4=pid[j];
                    pid[j]=pid[j+1];
                    pid[j+1]=t4;

                }
           }
      }

    for(int k=0;k<n;k++)
        {
            if (k==0)
                {
                    ct[0]=bt[0];
                    tat[0]=ct[0];
                    wt[0]=tat[0]-bt[0];

                }
            else
                {
                    ct[k]=ct[k-1]+bt[k];
                    tat[k]=ct[k]-at[k];
                    wt[k]=tat[k]-bt[k];
                }
        }

    printf("\nProcess Id:\t");
    for(j=0;j<n;j++)
    {
      printf("%d\t",pid[j]);
    }

    printf("\nArrival Time:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",at[j]);
        }

    printf("\nExecution Time:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",bt[j]);
        }

    printf("\nPriority:\t");
    for(j=0;j<n;j++)
        {
            printf("%d\t",pid[j]);
        }

    printf("\nCompletion Time:");
    for(k=0;k<n;k++)
        {
            printf("%d ",ct[k]);
        }

    printf("\nTurn Around Time:");
    for(k=0;k<n;k++)
        {
            printf("%d ",tat[k]);
        }

    printf("\nWaiting Time:");
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
