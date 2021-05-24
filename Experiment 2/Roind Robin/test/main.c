#include<stdio.h>
#include<stdlib.h>
int main()
{
    int temp,time_quantum=5;
    printf("Enter the number of processes:\n");
    scanf("%d", &temp);
    float arr[temp];

    int et;
    int wt[temp];
    for (int i = 0; i < temp; i++)
    {
        printf("Enter Execution Time of Processes %d\n", i + 1);
        scanf("%f", &arr[i]);
    }

    int rem_bt[temp];
    for (int i = 0 ; i < temp ; i++)
    {
        rem_bt[i] =  arr[i];
    }

    int t = 0;
    while (1)
    {
        int done = 1;

        for (int i = 0 ; i < temp; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > time_quantum)
                {
                    t += time_quantum;
                    rem_bt[i] -= time_quantum;
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

    float total_waiting_time=0;
    for (int x = 0; x < temp; x++)
    {
        printf("\nWaiting Time %d: %d\n",x+1,wt[x]);
        total_waiting_time=total_waiting_time+wt[x];
    }

    printf("\nAverage Waiting Time: %.2f\n",total_waiting_time/temp);
    int turnaround_time[temp];
     for (int i = 0; i < temp ; i++)
        {
            turnaround_time[i] = arr[i] + wt[i];
        }

     float total_turnaround_time=0;
     for(int i=0;i< temp;i++)
     {
         printf("\nTurn Around Time %d: %d\n",i+1,turnaround_time[i]);
        total_turnaround_time=total_turnaround_time+turnaround_time[i];
     }

     {
         printf("\nAverage Turn Around Time: %.2f\n",total_turnaround_time/temp);
     }
     for(int i=0;i< temp;i++)
     {
         printf("\nCompletion Time %d is: %d\n",i+1,turnaround_time[i]);
}
}
