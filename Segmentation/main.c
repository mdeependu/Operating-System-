/*#include<stdio.h>

int main()
{
    int seg[2][2]={{1000,500},{3000,200}};
    int i,j;
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            printf("\t%d",seg[i][j]);
        }
    }

    printf("\nBases are:");
    printf("\n1000");
    printf("\n3000");

    printf("\nLimits are:");
    printf("\n500");
    printf("\n200");


    int offset;
    printf("\nWhich Address: ");
    scanf("%d",&offset);
    int line;
    printf("\nWhich Line: ");
    scanf("%d",&line);

    return 0;

    int ans;
        if(offset<=limit){
            for(int i=0;i<seg;i++){
                if(i==line-1){
                    ans=segmentation[i][0]+offset;
                    printf("ANS:%d",ans);
                    break;
                }
        }
    }
    else{
        printf("Offset is greater than limit\n");
    }


}
*/

#include<stdio.h>

int main(){
    int N_seg;
    printf("enter the total number of segments :\n");
    scanf("%d",&N_seg);

    int segmentation[100][2];
    int temp=0;
    int address,limit;

    for(int i=0;i<N_seg;i++){
        printf("enter the base address and limit\n");
        scanf("%d %d",&segmentation[i][0],&segmentation[i][1]);
        if(segmentation[i][0]>=temp){

            temp=segmentation[i][0]+segmentation[i][1];
        }
        else{
            printf("invalid\n");
            exit(0);
        }
    }

    int offset,segnumber;
    printf("Enter the offset\n");
    scanf("%d",&offset);
    printf("Enter the segment number\n");
    scanf("%d",&segnumber);

    int ans;
    if(offset<=limit){
        for(int i=0;i<N_seg;i++){
            if(i==segnumber-1){
                ans=segmentation[i][0]+offset;
                printf("ANS:%d",ans);
                break;
            }
        }
    }
    else{
        printf("Invalid: offset is greater than limit\n");
    }
    return 0;
}
