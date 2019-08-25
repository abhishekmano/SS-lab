#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
        }
void main(){
        int size,init,n,pos,i;
        float total=0;

        printf("Enter the Disk size: ");
        scanf("%d",&size);
        printf("Enter the initial head position: ");
        scanf("%d",&init);
        pos=init;
        printf("Enter the number of requests: ");
        scanf("%d",&n);

        int *req=(int *)malloc(n*sizeof(int));
        printf("Enter the request\n");
        for(i=0;i<n;++i){
                scanf("%d",&req[i]);
                if(req[i]>=size || req[i]<0){
                        printf("are you dumb\n");
                        break;
                        }
                }
        for(i=0;i<n-1;++i){
                for(int j=i;j<n;++j)
                        if(req[i]>req[j])
                                swap(&req[i],&req[j]);
                }
        int min=0;
        for(min=0;req[min]<init;++min);
        //printf("%d",req[min]);
        min--;
        for(i=0;i<n;++i){
                if(req[i]<=init){
                        total+=init-req[i];
                        printf("Move from %d to %d with seek %d\n",init,req[i],init-req[i]);
                        }
                else{
                        total+=req[i]-init;
                         printf("Move from %d to %d with seek %d\n",init,req[i],req[i]-init);
                        }
                init=req[i];
                }

        printf("Total seek time is %f \n",total);
        printf("Average seek time is %f \n",total/n);

        }



