#include <stdio.h>

int main()
{
    /*Create*/
    FILE *fp;
    fp=fopen("os.txt","w");

    /*Write*/
    int i;
    char str[]="Hi I am Deependu\n";
    fp=fopen("os.txt","w");

    for (i=0;str[i]!='\n';i++)
    {
        fputc(str[i],fp);
    }
    fclose(fp);

    /*Read*/
    char c;
    fp=fopen("os.txt","r");
    while((c=getc(fp))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);

    /*Modify*/
    fp=fopen("os.txt","a");
    fputs("\nHow u Doin'",fp);
    fclose(fp);

    /*Read#2*/
    fp=fopen("os.txt","r");
    printf("\n");
    while((c=getc(fp))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);

    /*Delete*/
    if(remove("os.txt")==0)
    {
        printf("\nDeleted");
        break;
    }
    else
    {
        printf("\nNot Deleted");
        break;
    }

    return 0;
}
