#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
        }
int main(){
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
        for(min=0;req[min]<=init && min < n ;++min);
        min--;
	//printf("largest lowest is %d index %d \n",req[min],min);
        for(i=min;i>=0;--i){
                total+=init-req[i];
                printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],init-req[i]);
                init=req[i];
                }
	//printf("completed lower requests\n");
	if(min == n-1)
		return 0 ;
	if(init!=0){
		printf("Move from\t%d\tto\t0\twith seek %d\n",init,init);
		total+=init;
		init=0;
		}
	for(i=(min+1);i<n;++i){
		total+=req[i]-init;
		printf("Move from\t%d\tto\t%d\twith seek %d\n",init,req[i],req[i]-init);
		init=req[i];
		}

        printf("***Total seek time is %f*** \n",total);
        printf("***Average seek time is %f*** \n",total/n);
	return 0;
        }



