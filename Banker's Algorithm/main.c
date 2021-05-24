#include<stdio.h>

int main()
{
    int p;
    int r;

    printf("No. of Processes: ");
    scanf("%d",&p);

    printf("No. of Resources: ");
    scanf("%d",&r);

    int i,j;
    int max_need[10][10];
    int need[10][10];
    int allocate[10][10];

    printf("Enter Elements of Max Need:\n");
    for(i=0;i<p;i++)
        {
            for(j=0;j<r;j++)
                {
                    scanf("%d",&max_need[i][j]);
                }
        }

    printf("Enter Elements of Allocate:\n");
    for(i=0;i<p;i++)
        {
            for(j=0;j<r;j++)
                {
                    scanf("%d",&allocate[i][j]);
                }
        }

    printf("Need Matrix:\n");
    for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
                {
                    need[i][j] = max_need[i][j] - allocate[i][j];
                }
        }

    for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
                {
                    printf("%d",need[i][j]);
                }
            printf("\n");
        }

    int available[]={1,5,2};
    while (p>=1)
    {
        for(i=0;i<p;i++)
        {
            if(need[i][0]==0)
            {
                break;
            }
            while(j<3)
            {
                p--;
                available[j]=available[j]+allocate[i][j];
                need[i][j]=0;
                j++;
            }
        }
    }


    return 0;
}
