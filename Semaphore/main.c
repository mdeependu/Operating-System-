#include <stdio.h>

int x=1000;

int wait(int s)
{
    while(s==0);
    s=s-1;
    return s;
}

int signal(int s)
{
    s=s++;
    return s;
}


int main()
{
    int a=1;

    if(fork()==0)
        {
            printf("\nChild Process");
            wait(a);
            x = x + 1000;
            signal(a);
        }

    else
        {
            printf("\nParent Process");
            wait(a);
            x = x - 1000;
            signal(a);
        }

    printf("\nValue of x is %d",x);

    return 0;
}
