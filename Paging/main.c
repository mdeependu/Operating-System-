#include<stdio.h>
int main()
{
    int page[100],np,ps,f,i,pno,off;
    printf("No. of pages:\n");
    scanf("%d",&np);
    printf("Page size:\n");
    scanf("%d",&ps);
    printf("No. of frames:\n");
    scanf("%d",&f);
    printf("Enter page table:");
    printf("Enter frame number as -1 if no page present in frame:");
    for (i=0;i<np;i++)
    {
        printf("\n\n%d\t\t",i);
        scanf("%d",&page[i]);
    }
    printf("Logical Address:\n");
    printf("Page no:\n");
    scanf("%d",&pno);
    printf("Offset\n");
    scanf("%d",&off);
    if (page[pno]==-1)
    {
        printf("Page not available");
    }
    else
    {
        printf("Frame number and offset value are:%d%d\t",&page[pno],&off);
    }

    return 0;
}
