#include <stdio.h>
int main()
{
    //to get number of processes
    int count,q=5;
    printf("Enter the number of processes\n");
    scanf("%d", &count);
    float arr[count];
    //to get the burst time
    int burst_time;
    int wt[count];
    for (int i = 0; i < count; i++)
    {
        printf("enter the burst time of Process %d in milliseconds\n", i + 1);
        scanf("%f", &arr[i]);
    }
    //to get the waiting time
    int rem_bt[count];
    for (int i = 0 ; i < count ; i++)
        rem_bt[i] =  arr[i];

    int t = 0; // Current time

    while (1)
    {
        int done = 1;

        for (int i = 0 ; i < count; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > q)
                {
                    t += q;
                    rem_bt[i] -= q;
                }

                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - arr[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
          break;
    }
    //to print the waiting time
    float twt=0;
    for (int x = 0; x < count; x++)
    {
        printf("the waiting time of process %d is: %d\n",x+1,wt[x]);
        twt=twt+wt[x];
    }
    //to print avg waiting time
    printf("the avg waiting time is: %.2f\n",twt/count);
    //turnaroud time
    int turnaround_time[count];
     for (int i = 0; i < count ; i++)
     {
        turnaround_time[i] = arr[i] + wt[i];
     }
     //print turn around time
     float ttt=0;
     for(int i=0;i< count;i++)
     {
         printf("the turn around time of process %d is: %d\n",i+1,turnaround_time[i]);
        ttt=ttt+turnaround_time[i];
     }
     //avg turn around time
     {
         printf("the avg turn around time is: %.2f\n",ttt/count);
     }
     for(int i=0;i< count;i++)
     {
         printf("the completion time of process %d is: %d\n",i+1,turnaround_time[i]);
}
