#include<stdio.h>

int main(){
    int tq=5;
    int pid[]={1,2,3};
    int at[]={0,0,0};
    int et[]={6,4,7};
    int etx[3];
    int rt[6];
    int ct[45];

    int j=0;
    int l=0;
    int y=0;
    int t=0;
    printf("et:\n");
    for(int i=0;i<3;i++){
        rt[i]=et[i];
        etx[i]=et[i];

       printf("%d\n\n",rt[i]);
    }
    int ready_queue[10];
    int k=0;
    int flag=0;
    while(flag!=1){

         for(int j=0;j<3 ;j++){
            if(rt[0]==0 && rt[1]==0 && rt[2]==0){
                flag=1;
                break;
            }
            else{
                if(rt[j]>tq){
                    printf("%d",j);
                    ct[k]=tq;
                    rt[j]=rt[j]-tq;
                    printf("iff :%d",rt[j]);
                    ready_queue[k]=pid[j];
                    }

                else if(rt[j]==0){
                    rt[j]=0;
                    printf("%d ",j);
                    printf("elif:%d",rt[j]);
                    k--;
                    }

                else{
                    printf("%d",j);
                    ct[k]=rt[j];
                    if(k==5){
                        printf("%d",j);
                        printf("%d",rt[0]);
                    }


                    rt[j]=0;
                    printf("else:%d",rt[j]);
                    ready_queue[k]=pid[j];

                }

            printf("Array after Operation:%d%d%d\n",rt[0],rt[1],rt[2]);
            }


        }
    }

    printf("\nK %d",k);
    printf("\nprocess: ");
    for(int i=0;i<k;i++){
       printf("p%d ",ready_queue[i]);
    }
    printf("\nTIME:");
    for(int i=0;i<k;i++,l++){
        if (l==0){
            printf("%d",ct[l]);
        }
        else{
            ct[l]=ct[l-1]+ct[l];

            printf("%d",ct[l]);
        }
    }
    int store[3];
    for (int p=1;p<4;p++){
        for(int j=k-1;j>=0;j--){
            if(p==ready_queue[j]){
                store[p-1]=ct[j];
                break;

            }
        }
    }
    printf("\nct:");
    for(int i=0;i<3;i++){

        printf("%d ",store[i]);
    }

    int tat[3],wt[3];
    for (int a=0;a<3;a++){
        tat[a]=store[a]-at[a];
        wt[a]=tat[a]-etx[a];
    }
    printf("\net: ");
    for(int i=0;i<3;i++){

        printf("%d",etx[i]);
    }

    int a=0;
    printf("\ntat : %d%d%d",tat[a],tat[a+1],tat[a+2]);
    printf("\nwt: %d%d%d",wt[a],wt[a+1],wt[a+2]);

return 0;
}
